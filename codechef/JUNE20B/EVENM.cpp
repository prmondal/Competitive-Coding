#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"

inline void printSpiral(int m, int n) {
	int num = 1;
	int r = 0,c = 0;
	int a[m][n];
	const int M = m;
	const int N = n;

	while(r < m && c < n) {
		for (int j = c; j < n; j++) {
			a[r][j] = num++;
		}

		r++;

		for (int i = r; i < m; i++) {
			a[i][n-1] = num++;
		}

		n--;

		if (r < m) {
			for (int j = n - 1; j >= c; j--) {
				a[m-1][j] = num++;
			}

			m--;
		}

		if (c < n) {
			for (int i = m-1; i >= r; i--) {
				a[i][c] = num++;
			}

			c++;
		}
	}

	int i,j;
	rep(i,M) {
		rep(j,N) {
			cout << a[i][j] << " ";
		}

		cout << endl;
	}
}

void solve() {
	int n;
	cin>>n;
	printSpiral(n,n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}