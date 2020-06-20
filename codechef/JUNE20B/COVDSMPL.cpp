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
#define inf (1000*1000*1000+5)
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
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

bool solve() {
	int n,p;
	cin>>n>>p;
    int a[n][n];

    int i,j;
    rep(i,n){
        rep(j,n) {
            a[i][j] = 0;
        }
    }

    int total;
    cout << 1 << " " << 1 << " " << 1 << " " << n << " " << n << endl;
    cin >> total;

    int nextsum = 0;
    int prevsum = 0;

    for (int i = 1; i <= n; i+=2) {
        if (i < n-2) {
            cout << 1 << " " << i+2 << " " << 1 << " " << n << " " << n << endl;
            cin >> nextsum;
        } else {
            nextsum = 0;
        }

        int sum = total - nextsum - prevsum;
        prevsum = total - nextsum;
        //cout << "sum: " << sum << " prevsum: " << prevsum << " nextsum: " << nextsum << endl;

        for (int j = n-1; j >= 1; j--) {
            cout << 1 << " " << i << " " << 1 << " " << i+1 << " " << j << endl;
            int sum2;
            cin >> sum2;

            if (sum - sum2 == 2) {
                a[i-1][j] = 1;
                a[i][j] = 1;
            }

            if (sum - sum2 == 1) {
                cout << 1 << " " << i << " " << j+1 << " " << i << " " << j+1 << endl;
                cin >> a[i-1][j];

                if (a[i-1][j] != 1) a[i][j] = 1;
            }

            sum = sum2;
        }

        if (sum == 2) {
            a[i-1][0] = 1;
            a[i][0] = 1;
        } else if (sum == 1) {
            cout << 1 << " " << i << " " << 1 << " " << i << " " << 1 << endl;
            cin >> a[i-1][0];

            if (a[i-1][0] != 1) a[i][0] = 1;
        }
    }

    cout << 2 << endl;
    rep(i,n) {
        rep(j,n) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int x;
    cin >> x;

    if (x != 1) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        if (!solve()) exit(0);
    }
}