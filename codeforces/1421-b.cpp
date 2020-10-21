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

void solve() {
    int n; 
    cin >> n;

    vector<string> grid(n);
    rep(i, n) cin >> grid[i];

    int ans = 0;
    vii res;

    char x1 = grid[0][1];
    char x2 = grid[1][0];
    char y1 = grid[n-2][n-1];
    char y2 = grid[n-1][n-2];

    if (x1 == x2) {
        if (y1 == x1) {
            ans++;
            res.pb({n-2,n-1});
        }

        if (y2 == x2) {
            ans++;
            res.pb({n-1,n-2});
        }
    } else {
        if (y1 == '0' && y2 == '0') {
            if (x1 == '0') {
                ans++;
                res.pb({0,1});
            } else {
                ans++; 
                res.pb({1,0});
            }
        } else if (y1 == '1' && y2 == '1') {
            if (x1 == '1') {
                ans++;
                res.pb({0,1});
            } else {
                ans++; 
                res.pb({1,0});
            }
        } else if (y1 == '0' && y2 == '1') {
            if (x1 == '0') {
                ans++;
                res.pb({0,1});

                ans++;
                res.pb({n-1,n-2});
            } else {
                ans++; 
                res.pb({1,0});

                ans++; 
                res.pb({n-1,n-2});
            }
        } else if (y1 == '1' && y2 == '0') {
            if (x1 == '0') {
                ans++;
                res.pb({0,1});

                ans++;
                res.pb({n-2,n-1});
            } else {
                ans++; 
                res.pb({1,0});

                ans++; 
                res.pb({n-2,n-1});
            }
        }
    } 

    cout << ans << endl;
    for(auto e: res) cout << e.first + 1 << " " << e.second + 1 << endl;
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}