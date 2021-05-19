//Problem Link - https://codeforces.com/problemset/problem/617/E

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
#define uniq(v) v.erase(v.unique(all(v)), v.end())
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << endl

//#define TEST

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;
const int MAXN = 1e5+7;

ll ans = 0;
ll pref[MAXN];
umapi freq;

inline ll gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = 1LL << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
    int l;
    int r;
    int idx;
    ll ord;

    Query() {}

    Query(int l, int r, int idx): l(l), r(r), idx(idx) {
        ord = gilbertOrder(l, r, 21, 0);
    }

    bool operator<(const Query& o) const {
        return ord < o.ord;
    }
};

void add(int idx, int k) {
    ans += freq[pref[idx]^k];
    freq[pref[idx]]++;
}

void remove(int idx, int k) {
    ans -= freq[pref[idx]^k];
    freq[pref[idx]]--;
}

void solve() {
    int n, q, k;
    cin >> n >> q >> k;

    int arr[n];
    rep(i,n) {
        cin >> arr[i];

        if (i == 0) {
            pref[i] = arr[i];
        } else {
            pref[i] = pref[i-1]^arr[i];
        }
    }

    vector<Query> queries;
    vector<ll> answer(q);

    for (int i = 0; i < q; i++) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        queries.emplace_back(l,r,i);
    }

    sort(queries.begin(), queries.end());
    
    int currL = 0;
    int currR = -1;

    for (const auto& q: queries) {
        int qL = q.l;
        int qR = q.r;
        int qIdx = q.idx;

        while (currR < qR) {
            currR++;
            add(currR, k);
        }

        while (currR > qR) {
            remove(currR, k);
            currR--;
        } 

        while (currL < qL) {
            remove(currL, k);
            currL++;
        }

        while (currL > qL) {
            currL--;
            add(currL, k);
        }

        answer[qIdx] = ans;
    }

    for (int i = 0; i < q; i++) {
        cout << answer[i] << "\n";
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