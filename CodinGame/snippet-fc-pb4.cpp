int nSim = 0;
 
    vector<Action> myValidActions = getActionsToConsider(refGame, 0);
    myPrevAction                  = myValidActions[xorRandInt(myValidActions.size())];
 
    refGame.curDiscount          = 1.0;
    refGame.p[0].discountedScore = 0.0;
    refGame.p[1].discountedScore = 0.0;
 
    struct BeamNode {
      Action firstAction;
      Game   game;
      double score;
    };
 
    vector<BeamNode> states;  // Action at turn 0, current state
    vector<BeamNode> nextStates;
 
    for (Action& a : myValidActions) {
      Game sg = refGame;
 
      sg.leftoverSpells.resize(0);
      sg.leftoverPotions.resize(0);
 
      array<Action, 2> actions = {a, WAITACTION};
 
      print(a);
      applyActions(sg, actions);
 
      states.push_back({a, sg, 0.0});
    }
 
    bool doContinue = true;
    int  depth      = 1;
    while (true) {
      LOGA("depth " SPACE depth SPACE "size" SPACE states.size());
      for (auto& beamNode : states) {
        const Game&    g            = beamNode.game;
        const Action&  firstAction  = beamNode.firstAction;
        vector<Action> validActions = getActionsToConsider(g, 0);
        if (depth > 1) {
          validActions.erase(
              remove_if(validActions.begin(), validActions.end(), [](auto& a) { return a.type == ActionType::LEARN; }),
              validActions.end());
        }
        for (Action& a : validActions) {
          Game sg = g;
          array<Action, 2> actions = {a, WAITACTION};
 
          applyActions(sg, actions);
 
          nSim += 1;
 
          nextStates.push_back({firstAction, sg, evaluate(sg, 0)});
 
          if (timer.elapsed() > 40000) {
            doContinue = false;
            break;
          }
        }
        if (!doContinue) { break; }
      }
      if (!doContinue) { break; }
 
      swap(nextStates, states);
      nextStates.resize(0);
 
      sort(states.begin(), states.end(), [](auto& n1, auto& n2) {
        return (n1.game.hashValue != n2.game.hashValue) ? (n1.game.hashValue < n2.game.hashValue) : (n1.score > n2.score);
      });
      states.erase(
          unique(states.begin(), states.end(), [](auto& n1, auto& n2) { return n1.game.hashValue == n2.game.hashValue; }),
          states.end());
      // Deduplication is done
 
      constexpr int BEAMSIZE = 400;
      if (states.size() > BEAMSIZE) {
        nth_element(states.begin(), states.begin() + BEAMSIZE, states.end(),
                    [](auto& n1, auto& n2) { return n1.score > n2.score; });
        states.erase(states.begin() + BEAMSIZE, states.end());
      }
      // Beam is done
 
      depth += 1;
    }
 
    LOGA("Depth reached" SPACE depth SPACE nSim);
 
    double bestScore  = -100000.0;
    Action bestAction = WAITACTION;
    for (auto& beamNode : states) {
      const Game& g  = beamNode.game;
      beamNode.score = evaluate(g, 0);
    }
    bestAction =
        max_element(states.begin(), states.end(), [](auto& b1, auto& b2) { return b1.score < b2.score; })->firstAction;