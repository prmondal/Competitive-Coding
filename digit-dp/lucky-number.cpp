//https://www.codingame.com/ide/puzzle/the-lucky-number

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

const int MAX_DIGITS = 20;
ll dp[MAX_DIGITS][2][2][2];

ll digitDP(const string& num, int pos = 0, int c6 = 0, int c8 = 0, int tight = 1) {
    if (c6 && c8) return 0;
    if (pos == num.length()) return c6 || c8;
    if (dp[pos][c6][c8][tight]!=-1) return dp[pos][c6][c8][tight];

    int end = tight ? num[pos]-'0' : 9;
    ll c = 0;
    for (int i = 0; i <= end; i++) {
        c += digitDP(num, pos+1, c6 || (i==6), c8 || (i==8), tight && (i==end));
    }

    return dp[pos][c6][c8][tight] = c;
}

string decrease(string num) {
    int pos = num.length()-1;
    
    while(pos) {
        if (num[pos]=='0')
            num[pos] = '9';
        else {
            num[pos] = (num[pos]-'0')-1+'0';
            break;
        }

        pos--;
    }
    
    return num;
}

void solve() {
    string a,b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    ll ans = digitDP(b);
    memset(dp, -1, sizeof(dp));
    ans -= digitDP(decrease(a));
    cout << ans << endl;
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