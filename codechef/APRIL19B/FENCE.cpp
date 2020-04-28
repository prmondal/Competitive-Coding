#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;

        vector<pair<int, int>> plants;
        unordered_set<string> st;

        for(int i = 1; i <= k; i++) {
            int r,c;
            cin >> r >> c;

            plants.push_back(make_pair(r, c));

            string k = to_string(r) + "-" + to_string(c);
            st.emplace(k);
        }

        int ans = 0;

        for(auto p: plants) {
            int r = p.first;
            int c = p.second;
            
            for(int i = 0; i < 4; i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                string k = to_string(rr) + "-" + to_string(cc);

                if(rr >= 1 && rr <= n && cc >= 1 && cc <= m && (st.find(k) == st.end())) ans++;
                else if(rr > n || rr <= 0 || cc > m || cc <= 0) ans++;
            }
        }

        cout << ans << endl;
    }
}
