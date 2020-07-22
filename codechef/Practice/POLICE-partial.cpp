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

struct point {
	ll x, y, id;

	point() {}
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

ll dot(point v1, point v2) {
	return v1.x*v2.x+v1.y*v2.y;
}

ll sqDist(point p1, point p2) {
	return dot(p1-p2, p1-p2);
}

vector<point> convexHull(vector<point>& input) {
	if (input.size() <= 3) return input;

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

bool collinear(point p1, point p2, point p3) {
	return (p2.y-p1.y)*(p3.x-p2.x) == (p3.y-p2.y)*(p2.x-p1.x);
}

void solve() {
	int n,m;
	cin >> n >> m;
	vector<point> input;

	for (int i = 1; i <= n+m; i++) {
		ll x,y;
		cin>>x>>y;
		input.pb({x,y,(i <= n) ? 1 : 2}); //1: Police, 2: Thief
	}

	vector<point> hull = convexHull(input);
	// for (auto e: hull) {
	// 	cout << e.x << " " << e.y << endl;
	// }

	int cp = 0;
	int ct = 0;

	int i, s = hull.size();
	int st = -1, et = -1;
	vector<pii> groups;

	rep(i,s) {
		point& p = hull[i];

		if (p.id == 1) {
			cp++;

			if (st < 0) st = i;
		} else {
			ct++;

			if (st >= 0) {
				et = i-1;
				groups.pb({st,et});
				
				st = -1;
				et = -1;
			}
		}
	}

	//Case: 0
	if (ct == 0) {
		cout << 0 << endl;
		return;
	}

	//Case: 3
	if (cp == 0) {
		cout << 3 << endl;
		return;
	}

	// check for last group if any
	if (st > 0) {
		i = st;

		while(true) {
			point& p = hull[i];

			if (p.id == 2) {
				et = i-1;

				if (et < 0) {
					et = s-1;
				}

				groups.pb({st,et});
				break;
			}

			i = (i+1)%s;
		}
	}

	bool allCollinear = true;
			
	for (int j = 0; j < s-2; j++) {
		allCollinear &= collinear(hull[j],hull[j+1],hull[j+2]);
	}

	for (auto& g: groups) {
		point prevThief, nextThief;
		int schain = g.first;
		int echain = g.second;

		if (schain <= echain) {
			int prevIdx = schain-1;
			if (prevIdx < 0) prevIdx = s-1;

			prevThief = hull[prevIdx];
			nextThief = hull[(echain+1)%s];
		} else {
			prevThief = hull[schain-1];
			nextThief = hull[(echain+1)%s];
		}

		if (sqDist(prevThief, nextThief) < sqDist(hull[schain], hull[echain]) || (sqDist(prevThief, nextThief) == 0 && sqDist(prevThief, nextThief) == sqDist(hull[schain], hull[echain]))) {
			if (!allCollinear) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}

			return;
		}
	}

	if (allCollinear && s >= 3) {
		cout << 3 << endl;
	} else {
		cout << 2 << endl;
	}
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

/*

1 3 2
8 10 14 8 14 4 4 6 8 2
1

1
3 1
10 0
10 6
10 10
10 5

2
*/