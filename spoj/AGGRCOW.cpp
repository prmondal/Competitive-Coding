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

#define TEST

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(l, r) uniform_int_distribution<int>(l, r)(rng)

const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;
const int maxn = 1e5+7;

ll arr[maxn];
int n,c;

bool check(ll dist) {
    int lastIdx = 0;
    int currIdx = 1;
    int cows = c;
    cows--;

    while (currIdx < n) {
        if (arr[currIdx] - arr[lastIdx] >= dist) {
            if (cows-- == 1) return true;
            lastIdx = currIdx;
        }

        currIdx++;
    }

    return false;
}

void solve() {
    memset(arr, 0, sizeof(arr));

    int i;
    cin >> n >> c;

    rep(i,n) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    ll ans = -1;
    ll low = 0;
    ll high = arr[n-1];
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

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