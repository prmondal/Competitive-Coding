// https://www.spoj.com/problems/APIO10A/
// Gives WA at TC 11 but same code gets accepted in dmoj
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

#define TEST

// Use mt19937_64 for 64 bit random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(l, r) uniform_int_distribution<int>(l, r)(rng)
#define shuf(v) shuffle(all(v), rng);

const int INF = 0x3f3f3f3f;
const ll INFL = 1LL << 61;
const double PI  = acos(-1);
const double EPS = 1e-9;

//https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

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

void solve() {
    ll n=in(),a=in(),b=in(),c=in(),i;
    ll p[n];
    ll best;
    
    ll r = 0;
    rep(i,n) {
        ll v=in();
        r += v;
        p[i] = r;
    }

    /*
        dp[i] = max{0<=j<i}(dp[j] + f(sum(j+1,i)))
        f(x)=a*x*x+b*x+c

        dp[j] + f(sum(j+1,i))
        = dp[j] + f(x[j+1]+x[j+2]+...+x[i-1]+x[i])
        = dp[j] + f(p[i]-p[j])
        = dp[j] + a*p[i]*p[i] + a*p[j]*p[j] - 2*a*p[i]*p[j] + b*p[i] - b*p[j] + c

        C = a*p[i]*p[i] + b*p[i] + c
        m = -2*a*p[j]
        k = a*p[j]*p[j] - b*p[j] + dp[j]
    */

    LineContainer LC;
    LC.add(0,0);
    rep(i,n) {
        best = (a*p[i] + b)*p[i] + c + LC.query(p[i]);
        LC.add(-2*a*p[i], (a*p[i] - b)*p[i] + best);
    }

    cout << best << endl;
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