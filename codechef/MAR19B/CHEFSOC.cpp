#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int count(int v, bool visited[], vector<int> adj[]) {
    int c = 0;
    visited[v] = true;
    
    for(auto e: adj[v]) {
        if(!visited[e]) {
            c = (c + count(e, visited, adj)) % MOD;
        }
    }
    
    c = (c + 1) % MOD;
    visited[v] = false;
    
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> adj[n];
        bool* visited = new bool[n];

        for(int i = 1; i <= n; i++) {
            visited[i-1] = false;
            int s = a[i-1];

            for(int j = i-s; j <= i+s; j++) {
                if(i == j) continue;

                if(j >= 1 && j <= n) {
                    adj[i-1].push_back(j-1);
                }
            }
        }

        
        cout << count(0, visited, adj) << endl;
    }
}
