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
    cin>>n;

    string s;
    cin >> s;
    
    bool clockwise = true;

    for (int i = 0; i < n; i++) {
        if (s[i] == '<') {
            clockwise = false;
            break;
        } 
    }

    if (clockwise) {
        cout << n << endl;
        return;
    }

    bool anticlockwise = true;

    for (int i = 0; i < n; i++) {
        if (s[i] == '>') {
            anticlockwise = false;
            break;
        } 
    }

    if (anticlockwise) {
        cout << n << endl;
        return;
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (s[i-1] == '-' || s[i] == '-') ans++;
    }

    if (s[0] == '-' || s[n-1] == '-') ans++;

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