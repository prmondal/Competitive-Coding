#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a-1;i>=b;i--)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+7)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define tri2 pair<pii,int>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define viii2 vector<tri2>
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define coutp(i) cout << fixed << setprecision(i)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const double pi = acos(-1.0);

void solve() {
    int n;
    cin >> n;

    vi v(n+1), k(n+1, 0), prev(n+1, 0);
    int i;

    f(i,1,n+1) {
        cin >> v[i-1];

        int x = v[i-1];
        k[x] = max(k[x], i - prev[x]);
        prev[x] = i;
    }

    vi ans(n+1, -1);

    f(i,1,n+1) {
        k[i] = max(k[i], n+1-prev[i]);

        int j;
        f(j,k[i],n+1) {
            if (ans[j] != -1) break;
            ans[j] = i;
        }    
    }

    f(i,1,n+1) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}