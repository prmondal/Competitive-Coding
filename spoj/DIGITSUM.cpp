// Problem Link - https://www.spoj.com/problems/PR003004/
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

const int MAX_DIGITS = 18;
const int MAX_SUM = 9*MAX_DIGITS;
ll dp[MAX_DIGITS][MAX_SUM][2];

ll digitSum(string num, int pos = 0, ll sum = 0, int tight = 1) {
    if (pos == num.length()) return sum;
    if (dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];

    ll res = 0;
    if (tight) {
        const int n = num[pos]-'0';
        for (ll i = 0; i <= n; i++) {
            res += digitSum(num, pos+1, sum+i, (i==n));
        }
    } else {
        for (ll i = 0; i <= 9; i++) {
            res += digitSum(num, pos+1, sum+i, 0);
        }
    }

    return dp[pos][sum][tight] = res;
}

void solve() {
    int n,i;
    cin >> n;

    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        ll sum = digitSum(to_string(b));

        if (a > 0) {
            memset(dp, -1, sizeof(dp));
            sum -= digitSum(to_string(a-1));
        }

        cout << sum << endl;
    }
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