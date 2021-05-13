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
    string s;
    cin>>s;

    unordered_map<char,int> m;
    for(auto c:s){
        if(m.find(c)!=m.end())m[c]++;
        else m[c]=1;
    }

    int ans=0;
    auto it = m.begin();
    for (;it != m.end(); it++) {
        ans += it->second/2;
    }

    cout << min(ans,(int)sz(s)/3) << endl;
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
//aaabbb - 2
//aaaabbcc - 2
//aabbbbccdd - 3
//aabbccdde - 3
//abcdd - 1
//aaaabcccc - 3