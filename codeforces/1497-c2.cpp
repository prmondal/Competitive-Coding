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

const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;

void solve() {
    int n, k;
    cin>>n>>k;

    int i;
    if (n==k) {
        rep(i,k) {
            if (i==k-1) cout << 1 << endl;
            else cout << 1 << " ";
        }
        return; 
    }

    n = n-k+3;

    if (n&1) {
        cout << 1 << " " << (n-1)/2 << " " << (n-1)/2;
    } else {
        int c = n/2;
        if (!(c&1)) {
            cout << (n-c)/2 << " " << (n-c)/2 << " " << n/2;
        } else {
            cout << 2 << " " << n/2-1 << " " << n/2-1;
        }
    }

    rep(i,k-3) {
        cout << " " << 1;
    }
    cout << endl;
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