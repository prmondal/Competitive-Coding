// https://codeforces.com/problemset/problem/321/E

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
const int MAXN = 4007;
const int MAXK = 807;

int dp[MAXK][MAXN], opt[MAXK][MAXN];
int prefSum[MAXN][MAXN];

inline int in() {
	bool minus = false;
	int result = 0;
	char ch = getchar();
	while (true) {
		if(ch == '-')
			break;
		if(ch >= '0' && ch <= '9')
			break;
		ch = getchar();
	}
	if(ch == '-')
		minus = true;
	else
		result = ch-'0';
	while(true) {
		ch = getchar();
		if (ch < '0' || ch > '9')
			break;
		result = result*10 + (ch - '0');
	}
	return minus?-result:result;
}

inline int cost(int i, int j) {
    return prefSum[j][j] - prefSum[i-1][j] - prefSum[j][i-1] + prefSum[i-1][i-1];
}

void solve() {
    int n = in(), k = in();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int u = in();

            if (i == 1 && j == 1) prefSum[i][j] = u;
            else if (i > 1 && j > 1) prefSum[i][j] = u + prefSum[i-1][j] + prefSum[i][j-1] - prefSum[i-1][j-1];
            else if (i > 1) prefSum[i][j] = u + prefSum[i-1][j];
            else prefSum[i][j] = u + prefSum[i][j-1];
        }
    }

    for (int pos = 1; pos <= n; pos++) opt[0][pos] = 0;
    for (int g = 1; g <= k; g++) opt[g][n+1] = n;
    for (int pos = 1; pos <= n; pos++) dp[1][pos] = cost(1,pos);

    for (int g = 2; g <= k; g++) {
        for (int pos = n; pos >= 1; pos--) {
            dp[g][pos] = INF;
            for (int end = opt[g-1][pos]; end <= opt[g][pos+1]; end++) {
                int curr = dp[g-1][end] + cost(end+1,pos);
                if (curr < dp[g][pos]) {
                    dp[g][pos] = curr;
                    opt[g][pos] = end;
                }
            }
        }
    }

    cout << dp[k][n]/2 << endl;
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