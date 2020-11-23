#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <chrono>

using namespace std;

const int REST_DUMMY_SPELL_ID = -2;
const int DEADLINE = 45;
const int MAX_SPELL_LEARNED = 8;
const int MAX_SPACE = 10;

struct Spell {
    int actionId = -1; // the unique ID of this spell or recipe
    string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
    int delta0 = 0; // tier-0 ingredient change
    int delta1 = 0; // tier-1 ingredient change
    int delta2 = 0; // tier-2 ingredient change
    int delta3 = 0; // tier-3 ingredient change
    int price; // the price in rupees if this is a potion
    int tomeIndex = 0; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax
    int taxCount = 0; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell
    bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
    bool repeatable;
    bool learned;
    int repeatCount = 1;

    void print() const {
        cerr << "[Id: " << actionId << ", Type: " << actionType << "] " << delta0 << " " << delta1 << " " << delta2 << " " << delta3 << endl;
    }

    bool isPositive() const {
        return delta0 >= 0 && delta1 >= 0 && delta2 >= 0 && delta3 >= 0;
    }

    int value() const {
        int val = 0;
        if (delta0 > 0) val += delta0;
        if (delta1 > 0) val += 2*delta1;
        if (delta2 > 0) val += 3*delta2;
        if (delta3 > 0) val += 4*delta3;

        return val;
    }

    bool onlyPositiveBlueGems() const {
        return delta0 > 0 && delta1 == 0 && delta2 == 0 && delta3 == 0;
    }
};

struct State {
    int inv0 = 0; // tier-0 ingredients in inventory
    int inv1 = 0;
    int inv2 = 0;
    int inv3 = 0;
    int score; // amount of rupees
    Spell parentAction;
    
    bool covers(const State& o) {
        return o.inv0 <= inv0 && o.inv1 <= inv1 && o.inv2 <= inv2 && o.inv3 <= inv3;
    }

    void print() const {
        cerr << inv0 << " " << inv1 << " " << inv2 << " " << inv3 << endl;
    }

    string key() const {
        return to_string(inv0) + "-" + to_string(inv1) + "-" + to_string(inv2) + "-" + to_string(inv3);
    }

    bool isEmpty() {
        return inv0 + inv1 + inv2 + inv3 == 0;
    }

    int exceededCapacity() {
        return inv0 + inv1 + inv2 + inv3 > MAX_SPACE;
    }

    int spacesLeft() {
        return MAX_SPACE - (inv0 + inv1 + inv2 + inv3);
    }
};

struct Node {
    State state;
    struct Node* parentState = nullptr;
    vector<Spell> castSpells;
};

bool isInvEnough(const State& st, const Spell& spl) {
    if (abs(spl.delta0) <= st.inv0 && abs(spl.delta1) <= st.inv1 && abs(spl.delta2) <= st.inv2 && abs(spl.delta3) <= st.inv3) return true;
    return false;
}

vector<Spell> getNeighbours(const vector<Spell>& castSpells, const State& myState) {
    vector<Spell> nghbrs;
    bool exhaustedAny = false;

    for(auto spl: castSpells) {
        if (spl.castable) {
            nghbrs.push_back(spl);
        }
        else {
            exhaustedAny = true;
        }
    }

    if (exhaustedAny) {
        Spell restSpell;
        restSpell.actionId = REST_DUMMY_SPELL_ID;
        nghbrs.push_back(restSpell);
    }

    return nghbrs;
}

vector<Spell> restoredSpells(const vector<Spell>& castSpells) {
    vector<Spell> restoredCastSpells = castSpells;
    for (auto& spl: restoredCastSpells) spl.castable = 1;
    return restoredCastSpells;
}

vector<Spell> consumeAndUpdateCastSpells(const vector<Spell>& castSpells, const Spell& castedSpell) {
    vector<Spell> updatedCastSpells = castSpells;
    for (auto& spl: updatedCastSpells) {
        if (spl.actionId == castedSpell.actionId && !spl.repeatable) {
            spl.castable = 0;
            break;
        }
    }

    return updatedCastSpells;
}

vector<Spell> bestMoves(const State& startState, const vector<Spell>& targetCustomerOrders, const vector<Spell>& castSpells, Spell& winnerCustomer) {
    auto start = chrono::high_resolution_clock::now();
    unordered_set<string> visited;
    queue<Node*> q;
    
    Node* qs = new Node();
    qs->state = startState;
    qs->castSpells = castSpells;
    q.push(qs);

    Node* winnerNode = nullptr;
    int bestPrice = 0;
    
    while(!q.empty()) {
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); 
        if(duration.count() > DEADLINE) break;

        Node* currNode = q.front();
        q.pop();
        
        for (const auto& o: targetCustomerOrders) {
            State custOrderState;
            custOrderState.inv0 = abs(o.delta0);
            custOrderState.inv1 = abs(o.delta1);
            custOrderState.inv2 = abs(o.delta2);
            custOrderState.inv3 = abs(o.delta3);

            if (currNode->state.covers(custOrderState)) {
                if (o.price > bestPrice) {
                    bestPrice = o.price;
                    winnerNode = currNode;
                    winnerCustomer = o;
                }
            }
        }

        visited.insert(currNode->state.key());

        auto currCastSpells = currNode->castSpells;

        vector<Spell> nghbrs = getNeighbours(currCastSpells, currNode->state);

        for (const auto& spl: nghbrs) {
            State nextState = currNode->state;

            // rest
            if (spl.actionId == REST_DUMMY_SPELL_ID) {
                nextState.parentAction = spl;

                Node* nextNode = new Node();
                nextNode->state = nextState;
                nextNode->parentState = currNode;
                nextNode->castSpells = restoredSpells(currCastSpells);
                q.push(nextNode);
            }
            else {
                nextState.inv0 += spl.delta0;
                nextState.inv1 += spl.delta1;
                nextState.inv2 += spl.delta2;
                nextState.inv3 += spl.delta3;

                if (!nextState.exceededCapacity() && nextState.inv0 >= 0 && nextState.inv1 >= 0 && nextState.inv2 >= 0 && nextState.inv3 >= 0) {
                    if (visited.find(nextState.key()) == visited.end()) {
                        nextState.parentAction = spl;

                        Node* nextNode = new Node();
                        nextNode->state = nextState;
                        nextNode->parentState = currNode;
                        nextNode->castSpells = consumeAndUpdateCastSpells(currCastSpells, spl);
                        q.push(nextNode);
                    }
                }
            }
        }
    }

    vector<Spell> moves;
    
    if (!winnerNode) return moves;
    
    while(true) {
        Spell actionTaken = winnerNode->state.parentAction;
        moves.insert(moves.begin(), actionTaken);
        if (!winnerNode->parentState) break;
        
        int repeatCount = 0;

        while (true) {
            winnerNode = winnerNode->parentState;

            if (winnerNode && winnerNode->state.parentAction.actionId == actionTaken.actionId) {
                repeatCount++;
            } else {
                break;
            }
        }

        moves[0].repeatCount += repeatCount;
    }

    moves.erase(moves.begin()); // ignore parent action of start state
    return moves;
}

bool orderAvailable(const vector<Spell>& customerOrders, const Spell& targetCustomerOrder) {
    return std::find_if(customerOrders.begin(), customerOrders.end(), [&] (const Spell& order) { return order.actionId == targetCustomerOrder.actionId;}) != customerOrders.end();
}

int getNextLearnSpell(const vector<Spell>& learnSpells, const State& myState) {
    if (learnSpells.empty()) return -1;

    vector<Spell> positiveSpells;
    for (auto const& s: learnSpells) {
        if (s.isPositive()) positiveSpells.push_back(s);
    }

    sort(positiveSpells.begin(), positiveSpells.end(), [] (const Spell& s1, const Spell& s2) {
        return s1.value() > s2.value();
    });

    int blueGems = myState.inv0;

    for(const auto& spl: positiveSpells) {
        if (blueGems >= spl.tomeIndex) {
            return spl.actionId;
        }
    }

    return learnSpells[0].actionId;
}

int main()
{
    int learnedSpellCount = 0;
    
    // game loop
    while (1) {
        int actionCount; // the number of spells and recipes in play
        cin >> actionCount; cin.ignore();

        vector<Spell> brewSpells, castSpells, oppCastSpells, learnSpells;
        for (int i = 0; i < actionCount; i++) {
            Spell spl;
            cin >> spl.actionId >> spl.actionType >> spl.delta0 >> spl.delta1 >> spl.delta2 >> spl.delta3 >> spl.price >> spl.tomeIndex >> spl.taxCount >> spl.castable >> spl.repeatable; cin.ignore();
            
            if (spl.actionType == "BREW")
                brewSpells.push_back(spl);
            else if (spl.actionType == "CAST")
                castSpells.push_back(spl);
            else if (spl.actionType == "LEARN")
                learnSpells.push_back(spl);
            else 
                oppCastSpells.push_back(spl);    
        }
        
        vector<State> states;
        for (int i = 0; i < 2; i++) {
            State st;
            cin >> st.inv0 >> st.inv1 >> st.inv2 >> st.inv3 >> st.score; cin.ignore();
            states.push_back(st);
        }

        auto myState = states[0];

        sort(brewSpells.begin(), brewSpells.end(), [](const Spell& s1, const Spell& s2) {
            return s1.price > s2.price;
        });

        bool brewPossible = false;
        for (const auto& s: brewSpells) {
            if (isInvEnough(myState, s)) {
                cout << "BREW " << s.actionId << endl;
                brewPossible = true;
                break;
            }
        }

        if (learnedSpellCount < MAX_SPELL_LEARNED) {
            int id = getNextLearnSpell(learnSpells, myState);
            if (id >= 0) {
                cout << "LEARN " << id << endl;
                learnedSpellCount++;
            } else {
                cout << "WAIT" << endl;
            }
            
            continue;
        }

        if (!brewPossible) {
            Spell targetCustomer;
            vector<Spell> moves = bestMoves(myState, brewSpells, castSpells, targetCustomer);
            //for (auto m: moves) cerr << m.actionType << " " << m.actionId << " " << m.repeatCount << endl;

            if (moves.empty()) {
                int id = getNextLearnSpell(learnSpells, myState);
                if (id >= 0) {
                    cout << "LEARN " << id << endl;
                } else {
                    cout << "WAIT" << endl;
                }
                
                continue;
            }

            Spell currMove = moves.front();

            if (currMove.actionId != REST_DUMMY_SPELL_ID) {
                cout << "CAST " << currMove.actionId << " " << currMove.repeatCount << endl;
            } else {
                cout << "REST" << endl;
            }
        }
    }
}