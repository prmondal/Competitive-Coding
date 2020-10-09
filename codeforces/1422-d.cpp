#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define bit(x,i) (x&(1<<i))
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << endl

const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;

int main() {
    fastio;

    int n,m;
    cin >> n >> m;

    int sx,sy,fx,fy;
    cin >> sx >> sy >> fx >> fy;

    pii start = {sx,sy}, end = {fx,fy};

    vector<pair<pii, int>> teles(m);
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        teles[i] = {{x,y},i+1};
    }

    sort(all(teles));
    vector<vll> adjs(m+2);

    // edges between teles sorted by location
    f(i,1,m) {
        int id1 = teles[i].second;
        int id2 = teles[i-1].second;

        ll d = abs(teles[i].first.first - teles[i-1].first.first);
        adjs[id1].pb({d, id2});
        adjs[id2].pb({d, id1});
    }

    sort(all(teles), [](const auto& t1, const auto& t2) {
        return t1.first.second < t2.first.second;
    });

    f(i,1,m) {
        int id1 = teles[i].second;
        int id2 = teles[i-1].second;

        ll d = abs(teles[i].first.second - teles[i-1].first.second);
        adjs[id1].pb({d, id2});
        adjs[id2].pb({d, id1});
    }

    //edges between start to teles
    rep(i,m) {
        int id = teles[i].second;
        ll d = min(abs(teles[i].first.first - start.first), abs(teles[i].first.second - start.second));
        adjs[0].pb({d, id});
    }

    //edges between teles to end
    rep(i,m) {
        int id = teles[i].second;
        ll d = abs(teles[i].first.first - end.first) + abs(teles[i].first.second - end.second);
        adjs[id].pb({d, m+1});
    }
    
    //edge between start and end
    adjs[0].pb({abs(start.first - end.first) + abs(start.second - end.second), m+1});

    vll verts(m+2);
    rep(i,m+2) verts[i].first = infl, verts[i].second = i;
    verts[0].first = 0;

    priority_queue<pll,vll,greater<pll>> pq;
    pq.push(verts[0]);

    while(!pq.empty()) {
        pii top = pq.top();
        int u = top.second;
        pq.pop();

        for(auto& adj: adjs[u]) {
            ll w = adj.first;
            int v = adj.second;
            
            if (verts[v].first > verts[u].first + w) {
                verts[v].first = verts[u].first + w;
                pq.push(verts[v]);
            }
        }
    }

    // set<pii> s;
    // s.insert(verts[0]);

    // while(!s.empty()) {
    //     auto top = *(s.begin());
    //     int u = top.second;
    //     s.erase(s.begin());

    //     for(auto& adj: adjs[u]) {
    //         int w = adj.first;
    //         int v = adj.second;
            
    //         if (verts[v].first > verts[u].first + w) {
    //             if (verts[v].first != inf) {
    //                 s.erase(s.find(verts[v]));
    //             }

    //             verts[v].first = verts[u].first + w;
    //             s.insert(verts[v]);
    //         }
    //     }
    // }

    //for(auto e: verts) cout << e.first << endl;
    cout << verts[m+1].first << endl;
}
