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
    ll x,y;
    cin >> x >> y;

    ll c1,c2,c3,c4,c5,c6;
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

    c1 = min(c1, c2+c6);
    c2 = min(c2, c1+c3);
    c3 = min(c3, c2+c4);
    c4 = min(c4, c3+c5);
    c5 = min(c5, c4+c6);
    c6 = min(c6, c5+c1);

    ll ans = 0;

    if (x >= 0 && y <= 0) {
        ans += x*c6 + (-y*c5);
    } else if (x <= 0 && y >= 0) {
        ans += -x*c3 + y*c2;
    } else if (x >= 0 && y >= 0) {
        if (x < y) {
            ans += x*c1 + (y-x)*c2;
        } else {
            ans += y*c1 + (x-y)*c6;
        }
    } else {
        x = -x;
        y = -y;

        if (x < y) {
            ans += x*c4 + (y-x)*c5;
        } else {
            ans += y*c4 + (x-y)*c3;
        }
    }

    cout << ans << endl;
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}