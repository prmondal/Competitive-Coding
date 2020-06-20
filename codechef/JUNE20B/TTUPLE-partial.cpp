#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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
#define inf (1000*1000*1000+17)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define tri2 pair<pii,int>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define viii2 vector<tri2>
#define umapi unordered¸_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define coutp(i) cout << fixed << setprecision(i)
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"

ll minOps(ll p, ll q, ll r, ll a, ll b, ll c) {
	if (p == a && q == b && r == c) return 0;
	if (p == a && q == b) return 1;
	if (p == a && r == c) return 1;
	if (q == b && r == c) return 1;
    if (a == 0 && b == 0 && c == 0) return 1;
    
    if (a == 0 && b == 0) {
        if (c == r) return 1;
        return 2;
    }

    if (a == 0 && c == 0) {
        if (b == q) return 1;
        return 2;
    }

    if (b == 0 && c == 0) {
        if (a == p) return 1;
        return 2;
    }

    double x1=inf,x2=inf,x3=inf;
    ll y1=a-p,y2=b-q,y3=c-r;

	if (p != 0) x1=(double)a/p;
	if (q != 0) x2=(double)b/q;
	if (r != 0) x3=(double)c/r;

    if (y1 == y2 && y2 == y3) return 1;
    if (y1 == y2 && y1 == 0) return 1;
	if (y2 == y3 && y2 == 0) return 1;
	if (y1 == y3 && y1 == 0) return 1;

    //multiply by 0 and add x
	if (a != 0 && a == b && b == c) return 2;
    if (a == 0 && b != 0 && b == c) return 2;
	if (b == 0 && a != 0 && a == c) return 2;
	if (c == 0 && a != 0 && a == b) return 2;

    ll fx1 = floor(x1);
    ll fx2 = floor(x2);
    ll fx3 = floor(x3);

    //cout << p << " " << q << " " << r << " " << a << " " << b << " " << c << endl; 
    //cout << "fx1: " << fx1 << " fx2: " << fx2 << " fx3: " << fx3 << endl;
    //cout << "y1: " << y1 << " y2: " << y2 << " y3: " << y3 << endl;
    
    ll m1 = inf;

    if (fx1 != inf && fx1 != 1 && fx1 != 0) {
        if (p != a) m1 = min(1 + minOps(p*fx1,q,r,a,b,c), m1);
        if (p != a && q != b) m1 = min(1 + minOps(p*fx1,q*fx1,r,a,b,c), m1);
        if (p != a && r != c) m1 = min(1 + minOps(p*fx1,q,r*fx1,a,b,c), m1);
        if (p != a && q != b && r != c) m1 = min(1 + minOps(p*fx1,q*fx1,r*fx1,a,b,c), m1);
    }

    if (fx2 != inf && fx2 != 1 && fx2 != 0) {
        if (q != b) m1 = min(1 + minOps(p,q*fx2,r,a,b,c), m1);
        if (p != a && q != b) m1 = min(1 + minOps(p*fx2,q*fx2,r,a,b,c), m1);
        if (q != b && r != c) m1 = min(1 + minOps(p,q*fx2,r*fx2,a,b,c), m1);
        if (p != a && q != b && r != c) m1 = min(1 + minOps(p*fx2,q*fx2,r*fx2,a,b,c), m1);
    }

    if (fx3 != inf && fx3 != 1 && fx3 != 0) {
        if (r != c) m1 = min(1 + minOps(p,q,r*fx3,a,b,c), m1);
        if (q != b && r != c) m1 = min(1 + minOps(p,q*fx3,r*fx3,a,b,c), m1);
        if (p != a && r != c) m1 = min(1 + minOps(p*fx3,q,r*fx3,a,b,c), m1);
        if (p != a && q != b && r != c) m1 = min(1 + minOps(p*fx3,q*fx3,r*fx3,a,b,c), m1);
    }
	
    ll n1 = inf;

    if (y1 != 0) {
        if (p != a) n1 = min(1 + minOps(p+y1,q,r,a,b,c), n1);
        if (p != a && q != b) n1 = min(1 + minOps(p+y1,q+y1,r,a,b,c), n1);
        if (p != a && r != c) n1 = min(1 + minOps(p+y1,q,r+y1,a,b,c), n1);
        if (p != a && q != b && r != c) n1 = min(1 + minOps(p+y1,q+y1,r+y1,a,b,c), n1);
    }

    if (y2 != 0) {
        if (q != b) n1 = min(1 + minOps(p,q+y2,r,a,b,c), n1);
        if (q != b && r != c) n1 = min(1 + minOps(p,q+y2,r+y2,a,b,c), n1);
        if (p != a && q != b) n1 = min(1 + minOps(p+y2,q+y2,r,a,b,c), n1);
        if (p != a && q != b && r != c) n1 = min(1 + minOps(p+y2,q+y2,r+y2,a,b,c), n1);
    }

    if (y3 != 0) {
        if (r != c) n1 = min(1 + minOps(p,q,r+y3,a,b,c), n1);
        if (q != b && r != c) n1 = min(1 + minOps(p,q+y3,r+y3,a,b,c), n1);
        if (p != a && r != c) n1 = min(1 + minOps(p+y3,q,r+y3,a,b,c), n1);
        if (p != a && q != b && r != c) n1 = min(1 + minOps(p+y3,q+y3,r+y3,a,b,c), n1);
    }

    return min(m1,n1);
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void solve() {
	ll p,q,r,a,b,c;
	cin>>p>>q>>r>>a>>b>>c;
    
    ll g = 1;
    if (a != 0 && b != 0 && c != 0 && a != b && b != c && a != c) {
        g = abs(gcd(a,gcd(b,c)));
    }
    
    if (g != 1) {
        cout << min(minOps(p,q,r,a,b,c), 1 + minOps(p,q,r,a/g,b/g,c/g)) << endl;
    } else {
        cout << minOps(p,q,r,a,b,c) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // std::random_device device;
    // std::mt19937 generator(device());
    // std::uniform_int_distribution<ll> distribution(-10,10);
    
    // int t = 0;
    // while(t < 50) {
    //     vector<ll> v;
    //     for (int i = 1; i <= 6; i++) {
    //         v.push_back(distribution(generator));
    //     }
        
    //     for (auto& e: v) cout << e << " ";
    //     cout << endl;

    //     ll r = minOps(v[0],v[1],v[2],v[3],v[4],v[5]);
    //     if (r > 3) cout << "FAILED" << endl;
    //     t++;
    // }
    
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}

/*

1 0 3 5 6 -18 -24
2

0 3 5 -> 0 -18 -30 -> 6 -18 -24

6 -18 -24 -> 1 -3 -4

25
1 2 3 1 1 1
1 2 3 10 10 10
1000000000 1000000000 888888 -1010101010 -66666 11111
1 2 3 0 0 0
1 2 3 0 0 1
0 0 0 1 2 3
0 0 1 1 2 3
3 5 7 6 5 10
8 6 3 9 7 8
3 4 7 5 5 5
2 3 4 15 9 21
15 9 21 2 3 4
-2 -3 -4 -15 -20 -25
4 -3 -4 15 -20 -25
3 5 7 3 10 14
2 1 -2 0 2 2
1 2 3 0 0 3
1 2 3 0 2 0
1 2 3 1 0 0
3 4 5 0 4 4
2 3 5 6 11 7
4 5 6 11 13 15
3 2 6 15 4 18
0 3 5 6 -15 -19
0 3 5 6 -18 -24

2
2
3
1
2
2
2
1
2
2
2
3
2
2
1
2
1
1
1
2
2
2
2
2
2

*/

