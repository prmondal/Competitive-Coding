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

void solve() {
    int n,t;
    cin>>n>>t;

    vi v(n), ans(n, 0);
    umapi m1, m2;

    int i;
    rep(i,n) {
        cin >> v[i];
        int rest = t-v[i];

        if (m1.find(rest) == m1.end()) {
            m1[v[i]]++;
            ans[i] = 0;
        } else {
            if (m2.find(rest) == m2.end()) {
                m2[v[i]]++;
                ans[i] = 1;
            } else {
                if (m1[v[i]] < m2[v[i]]) {
                    m1[v[i]]++;
                    ans[i] = 0;
                } else {
                    m2[v[i]]++;
                    ans[i] = 1;
                }
            }
        }
    }

    rep(i,n) cout << ans[i] << " ";
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