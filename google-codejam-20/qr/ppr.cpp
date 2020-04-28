#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    int casecount = 0;
    while(t--) {
        casecount++;

        int n;
        cin>>n;
        vector<pair<int, pair<int,int>>> acts;

        for (int i = 1; i <= n; i++) {
            int s,e;
            cin>>s>>e;
            acts.push_back({i-1, {s,e}});
        }

        sort(acts.begin(), acts.end(), [](const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b) {
            if (a.second.first == b.second.first) return a.second.second < b.second.second;
            return a.second.first < b.second.first;
        });

        set<pair<int,int>> s1;
        set<pair<int,int>> s2;

        bool possible = true;
        string ans(n, 'X');

        for (int i = 0; i < n; i++) {
            int s = acts[i].second.first;
            int e = acts[i].second.second;
            int idx = acts[i].first;

            if (i > 0) {
                bool assigned = true;
                for (auto& intv: s1) {
                    if (s < intv.second) {
                        assigned = false;
                        break;
                    }
                }

                if (!assigned) {
                    assigned = true;
                    for (auto& intv: s2) {
                        if (s < intv.second) {
                            assigned = false;
                            break;
                        }
                    }

                    if (!assigned) {
                        possible = false;
                        break; 
                    } else {
                        s2.insert({s,e});
                        ans[idx] = 'C';
                    }
                } else {
                    s1.insert({s,e});
                    ans[idx] = 'J';
                }
            } else {
                s1.insert({s,e});
                ans[idx] = 'J';
            }
        }

        if (possible) {
            cout << "Case #" << casecount << ": " << ans << "\n";
        } else {
            cout << "Case #" << casecount << ": " << "IMPOSSIBLE" << "\n";
        }
    }
}