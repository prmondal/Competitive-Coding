#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define repr(i,n) for(int i=n-1;i>=0;i--)
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

typedef struct {
    ll len = 0;
    ll parts = 1;
    
    ll anotherSplitCost() {
        ll c1 = cost();
        parts++;
        ll c2 = cost();
        parts--;
        return c1 - c2;
    }

    ll cost () const {
        ll d1 = len / parts;
        ll n1 = len % parts;
        ll n2 = parts - n1;
        return d1*d1*n2 + (d1+1)*(d1+1)*n1;
    }
} node;

struct cmp {
    bool operator() (node& a, node& b) {
        return a.anotherSplitCost() < b.anotherSplitCost();
    }
};

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    priority_queue<node, vector<node>, cmp> pq;
    rep(i,n) {
        node n;
        cin >> n.len;
        pq.push(n);
    }
    
    k -= n;
    ll ans = 0;

    rep(i,k) {
        node t = pq.top();
        pq.pop();
        t.parts++;
        pq.push(t);
    }

    while(!pq.empty()) {
        ans += pq.top().cost();
        pq.pop();
    }

    cout << ans << endl;
}
