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
    int n,m;
    cin>>n>>m;
    int a[n][m];

    int i,j;
    rep(i,n) {
        rep(j,m) {
            cin>>a[i][j];
        }
    }

    vector<multiset<int>> v(n+m-1);
    unordered_map<string,int> mp;
    bool check[n+m-1];

    int k = 0;
    int p = 0;

    repr(i,n) {
        int mm = i;
        rep(j,k+1){
            v[p].insert(a[mm][j]);
            string key = to_string(mm)+'-'+to_string(j);
            mp[key]=p;
            mm++;
        }

        if (*v[p].begin() != *v[p].rbegin()){
            check[p]=0;
        } else {
            check[p]=1;
        }
        
        k++;
        p++;
    }

    for (int j=1; j<m;j++) {
        int mm = j;
        for (int i = 0; i < min(n,m-j); i++) {
            v[p].insert(a[i][mm]);
            string key = to_string(i)+'-'+to_string(mm);
            mp[key]=p;
            mm++;
        }

        if (*v[p].begin() != *v[p].rbegin()){
            check[p]=0;
        } else {
            check[p]=1;
        }

        p++;
    }
    
    int q;
    cin>>q;

    rep(i,q) {
        int x,y,val;
        cin>>x>>y>>val;
        x--;
        y--;
        
        string key = to_string(x)+'-'+to_string(y);
        int idx = mp[key];

        auto it = v[idx].find(a[x][y]);
        v[idx].erase(it);
        v[idx].insert(val);
        a[x][y] = val;
        
        if (*v[idx].begin() != *v[idx].rbegin()){
            check[idx]=0;
        } else {
            check[idx]=1;
        }
        
        bool good = true;
        for (const auto& b:check) {
            if (!b) {
                good=false;
                break;
            }
        }

        if (good) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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