#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a-1;i>=b;i--)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define tri2 pair<pii,int>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define viii2 vector<tri2>
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define coutp(i) cout << fixed << setprecision(i)
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int MAXN = 150;
vector<int> adj[MAXN];
int w[MAXN][MAXN];
int par[MAXN];
int vis[MAXN];

bool augmentPath(int source, int sink) {
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    par[source] = -1;

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        for(int i = 0; i < adj[t].size(); i++) {
            int next = adj[t][i];
            if (!vis[next] && w[t][next] > 0) {
                vis[next] = 1;
                par[next] = t;
                q.push(next);
            }
        }
    }

    return vis[sink] == 1;
}

int maxFlow(int source, int sink) {
    int maxf = 0;
    while(augmentPath(source, sink)) {
        int pathf = INT_MAX;
        for (int j = sink; j != source; j = par[j]) {
            int i = par[j];
            pathf = min(pathf, w[i][j]);
        }
        maxf += pathf;

        for (int j = sink; j != source; j = par[j]) {
            int i = par[j];
            w[i][j] -= pathf;
            w[j][i] += pathf;
        }
    }

    return maxf;
}

bool solve() {
	int n,p,i,j;
	cin>>n>>p;

    rep(i,MAXN) {
        par[i] = -1;
        vis[i] = 0;
        adj[i].clear();

        int j;
        rep(j,MAXN) {
            w[i][j] = 0;
        }
    }
    
    vector<int> rs(n,0);
    vector<int> cs(n,0);

    rep(i,n) {
        int rowsum;
        cout << 1 << " " << i+1 << " " << 1 << " " << i+1 << " " << n << endl;
        cin >> rowsum;
        if (rowsum == -1) return false; 
        rs[i] = rowsum;

        int colsum;
        cout << 1 << " " << 1 << " " << i+1 << " " << n << " " << i+1 << endl;
        cin >> colsum;
        if (colsum == -1) return false;
        cs[i] = colsum;
    }

    int source = 2*n+1;
    int sink = source + 1;

    rep(i,n) {
        adj[source].push_back(i);
        adj[i].push_back(source);
        w[source][i] = rs[i];
        w[i][source] = 0;
    }

    rep(i,n) {
        int j = i+n;
        adj[j].push_back(sink);
        adj[sink].push_back(j);
        w[j][sink] = cs[i];
        w[sink][j] = 0;
    }

    rep(i,n) {
        rep(j,n) {
            adj[i].push_back(j+n);
            adj[j+n].push_back(i);
            w[i][j+n] = 1;
            w[j+n][i] = 0;
        }
    }

    int maxf = maxFlow(source, sink);
    //cout << maxf << endl;

    cout << 2 << endl;
    rep(i,n) {
        rep(j,n) {
            cout << w[j+n][i] << " ";
        }
        cout << endl;
    }

    int x;
    cin >> x;

    if (x != 1) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        if (!solve()) exit(0);
    }
}