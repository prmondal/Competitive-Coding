//https://dmoj.ca/problem/apio10p1
//strict mem constraint
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
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
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << "\n"

//#define TEST

// Use mt19937_64 for 64 bit random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(l, r) uniform_int_distribution<int>(l, r)(rng)
#define shuf(v) shuffle(all(v), rng);

const int INF = 0x3f3f3f3f;
const ll INFL = 1LL << 61;
const double PI  = acos(-1);
const double EPS = 1e-9;

vector <long long> M;
vector <long long> B;
bool bad(int l1,int l2,int l3)
{
        return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
}
void add(long long m,long long b)
{
        M.push_back(m);
        B.push_back(b);
        while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
        {
                M.erase(M.end()-2);
                B.erase(B.end()-2);
        }
}
int pointer;
long long query(long long x)
{
        if (pointer >=M.size())
                pointer=M.size()-1;
        while (pointer<M.size()-1&&
          M[pointer+1]*x+B[pointer+1]>M[pointer]*x+B[pointer])
                pointer++;
        return M[pointer]*x+B[pointer];
}

void solve() {
    int n,a,b,c,i;
    cin >> n >> a >> b >> c;
    ll p[n];
    ll best;
    
    ll r = 0;
    rep(i,n) {
        ll v;
        cin >> v;
        r += v;
        p[i] = r;
    }

    /*
        dp[i] = max{0<=j<i}(dp[j] + f(sum(j+1,i)))
        f(x)=a*x*x+b*x+c

        dp[j] + f(sum(j+1,i))
        = dp[j] + f(x[j+1]+x[j+2]+...+x[i-1]+x[i])
        = dp[j] + f(p[i]-p[j])
        = dp[j] + a*p[i]*p[i] + a*p[j]*p[j] - 2*a*p[i]*p[j] + b*p[i] - b*p[j] + c

        C = a*p[i]*p[i] + b*p[i] + c
        m = -2*a*p[j]
        k = a*p[j]*p[j] - b*p[j] + dp[j]
    */

    add(0,0);
    rep(i,n) {
        best = a*p[i]*p[i] + b*p[i] + c + query(p[i]);
        add(-2*a*p[i], a*p[i]*p[i] - b*p[i] + best);
    }

    cout << best << endl;
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