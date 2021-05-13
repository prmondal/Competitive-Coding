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
    int n;
    cin>>n;
    string s,p;
    cin>>s>>p;

    if(s==p){
        cout<<"Yes"<<endl;
    } else{
        int pf1[n+1],pf2[n+1];
        pf1[0]=pf2[0]=0;

        int i;

        rep(i,n){
            pf1[i+1]=pf1[i]+(s[i]=='1');
            pf2[i+1]=pf2[i]+(p[i]=='1');
            
            if (p[i]=='1' && s[i]=='0' && pf1[i+1] < pf2[i+1]) {
                cout << "No" << endl;
                return;
            }
        }

        if (pf1[n] != pf2[n]) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
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