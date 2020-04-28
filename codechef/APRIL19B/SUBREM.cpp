#include <bits/stdc++.h>
using namespace std;

long int maxProfit(long int idx, vector<long int> adj[], long int x, long int a[], bool visited[]) {
    visited[idx] = 1;
    long int profit = 0;
    
    for(auto e: adj[idx]) {
        if(!visited[e]) profit += maxProfit(e, adj, x, a, visited);
    }
    
    return max(-x, a[idx] + profit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long int t;
    cin >> t;

    while(t--) {
        long int n, x;
        cin >> n >> x;

        long int a[n];
        for(long int i = 1; i <= n; i++) cin >> a[i-1];

        vector<long int> adj[n];
        for(long int i = 1; i <= n-1; i++) {
            long int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        
        bool visited[n] = {0};
        cout << maxProfit(0, adj, x, a, visited) << endl;
    }
}
