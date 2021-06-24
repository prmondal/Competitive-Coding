// https://www.spoj.com/problems/SAWMILL

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define bit(x,i) (x&(1<<i))
#define uniq(v) v.erase(v.unique(all(v)), v.end())
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << "\n"

//#define TEST

// Use mt19937_64 for 64 bit random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(l, r) uniform_int_distribution<int>(l, r)(rng)
#define shuf(v) shuffle(all(v), rng);

const int INF = 0x3f3f3f3f;
const ll INFL = 1LL << 61;
const double PI  = acos(-1);
const double EPS = 1e-9;
const int MAXN = 20007;

ll dp[10][MAXN];
ll c1[MAXN], c2[MAXN], p[MAXN];

inline ll cost(int i, int j) {
    return (c2[j]-c2[i-1]) - p[i-1]*(c1[j]-c1[i-1]);
}

void compute(int i, int L, int R, int optL, int optR) {
    if (L > R) return;

    int mid = (L + R) >> 1, savek = optL;
    dp[i][mid] = INFL;
    for(int k=optL;k<=min(mid-1, optR);k++) {
        ll cur = dp[i-1][k] + cost(k+1, mid);
        if (cur < dp[i][mid]) {
            dp[i][mid] = cur;
            savek = k;
        }
    }
    compute(i, L, mid-1, optL, savek);
    compute(i, mid+1, R, savek, optR);
}

void solve() {
    int n,k=3;
    cin >> n;

    vl w(n), d(n);

    int i;
    rep(i,n) {
        ll v1,v2;
        cin >> v1 >> v2;
        w.insert(w.begin(),v1);
        d.insert(d.begin(),v2);
    }

    ll r1 = 0, r2 = 0, r3 = 0;
    f(i,1,n+1) {
        r1 += d[i-1];
        r2 += w[i-1];
        p[i] = r1;
        r3 += w[i-1]*p[i];
        c1[i] = r2;
        c2[i] = r3;
    }
    
    dp[0][0] = 0;
    f(i,1,n+1) dp[0][i] = c2[i];
    f(i,1,k+1) compute(i, 1, n, 0, n);
    cout << dp[k][n] << endl;
}

int main() {
    fastio;
#ifdef TEST
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
#else
    solve();    
#endif    
}