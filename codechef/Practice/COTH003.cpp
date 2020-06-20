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

const int MAXN = 57;
int vis[MAXN];

struct point {
	ll x, y, id;

	point(ll x, ll y, int id): x(x),y(y),id(id) {}

	point operator-(const point& p) {
		return point({x-p.x, y-p.y, -1});
	}
};

ll cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

ll cross(point p1, point p2, point p3) {
	point v1 = p2-p1;
	point v2 = p3-p2;
	return cross(v1, v2);
}

vector<point> convexHull(vector<point>& input) {
	if (input.size() == 1) return vector<point>();

	sort(all(input), [] (const point& p1, const point& p2) {
		if (p1.y == p2.y) return p1.x < p2.x;
		return p1.y > p2.y;
	});

	point a = input.front();
	point b = input.back();

	int n = input.size();

	vector<point> up, down;
	up.pb(a);
	down.pb(a);

	for (int i = 1; i < n; i++) {
		while(up.size() >= 2 && cross(up[up.size()-2], up[up.size()-1], input[i]) > 0) up.pop_back();
		up.pb(input[i]);

		while(down.size() >= 2 && cross(down[down.size()-2], down[down.size()-1], input[i]) < 0) down.pop_back();
		down.pb(input[i]);
	}

	vector<point> hull;
	
	for (int i = 0; i < up.size(); i++) {
		hull.pb(up[i]);
	}

	for (int i = down.size() - 2; i > 0; i--) {
		hull.pb(down[i]);
	}

	return hull;
}

void solve() {
	memset(vis, 0, sizeof vis);

	int n;
	cin >> n;
	vector<point> input;

	for (int i = 1; i <= n; i++) {
		ll x,y;
		cin>>x>>y;
		input.pb({x,y,i});
	}

	vector<vector<point>> rings;
	vector<point> active = input;

	while(active.size() >= 3) {
		vector<point> hull = convexHull(active);
		for (auto& p : hull) {
			vis[p.id]=1;
		}

		rings.pb(hull);
		active.clear();

		for(auto& p: input) {
			if (!vis[p.id]) {
				active.pb(p);
			}
		}
	}

	for (auto& ring: rings) {
		cout << ring[0].x << " " << ring[0].y << " ";

		for (int i = ring.size()-1; i >= 1; i--) {
			cout << ring[i].x << " " << ring[i].y << " ";
		}
	}

	for (auto& e: active) {
		cout << e.x << " " << e.y << " ";
	}

	cout << endl;
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