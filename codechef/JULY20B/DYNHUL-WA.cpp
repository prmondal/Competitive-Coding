#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
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
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define coutp(i) cout << fixed << setprecision(i)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

const int MAXN = 1024 + 7;
int vis[MAXN];

struct point {
	ll x, y, id;

	point(ll x, ll y, int id): x(x),y(y),id(id) {}

	point operator-(const point& p) {
		return point({x-p.x, y-p.y, -1});
	}

	bool operator==(const point& p) {
		return id == p.id;
	}
};

typedef vector<point> points;

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
		if (p1.x == p2.x) return p1.y < p2.y;
		return p1.x < p2.x;
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
		if (find(hull.begin(), hull.end(), down[i]) == hull.end()) {
			hull.pb(down[i]);
		}
	}

	return hull;
}

float polArea(vector<point> pol) {
	float a, b = 0;
	int n = pol.size();
	if (n < 3) return 0;

	int i;

	rep (i, n-1) {
		a += (float)pol[i].x * pol[i+1].y;
		b += (float)pol[i].y * pol[i+1].x;
	}

	a += (float)pol[n-1].x*pol[0].y;
	b += (float)pol[n-1].y*pol[0].x;

	return abs(a-b)/2.0;
}

float triArea(point p1, point p2, point p3) {
	vector<point> pol;
	pol.pb(p1);
	pol.pb(p2);
	pol.pb(p3);

	return polArea(pol);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> input;

    int i;
	rep (i,n) {
		ll x,y;
		cin>>x>>y;
		input.pb({x,y,i+1});
	}

	int m;
	cin >> m;
	memset(vis, 0, sizeof vis);

	points currLayer = convexHull(input);
	for (auto& e: currLayer) {
		vis[e.id] = 1;
	}

	points active;
	for (auto& e: input) {
		if (!vis[e.id]) {
			active.pb(e);
		}
	}

	vector<int> ans;
	points nextLayer = convexHull(active);
	for (auto& e: nextLayer) {
		vis[e.id] = 1;
	}
	
	int removed[MAXN];
	memset(removed, 0, sizeof removed);

	while (nextLayer.size() > 2) {
		// cout << "/////////////First//////////////" << endl;
		// for(auto& e: currLayer) {
		// 	cout << e.id << endl;
		// }

		// cout << "/////////////Next//////////////" << endl;
		// for(auto& e: nextLayer) {
		// 	cout << e.id << endl;
		// }

		float currConvexArea = polArea(currLayer);
		float minArea = inf;
		int winningIdx = -1;
		points nextLayerRemainingWinner;
		points exposedLayerWinner;

		int j, ls = currLayer.size();
		rep(j, ls) {
			int prev;
			int next = (j+1) % ls;

			if (j == 0)
				prev = ls-1;
			else
				prev = j-1;

			points exposedLayer = nextLayer;
			exposedLayer.insert(exposedLayer.begin(), currLayer[j]);
			points hull = convexHull(exposedLayer);
			points nextLayerRemaining;
			int hs = hull.size();

			for (int k = 0; k < hs; k++) {
				if (k == 0 || k == 1 || k == hs - 1) continue; //prev and adj in new hull
				point curr = hull[k];
				
				auto it = find(exposedLayer.begin(), exposedLayer.end(), curr);
				if (it != exposedLayer.end()) {
					vis[curr.id] = 0;
					nextLayerRemaining.pb(curr);
					exposedLayer.erase(it);
				}
			}

			exposedLayer.erase(exposedLayer.begin());
			points exposedCopy = exposedLayer;
			exposedLayer.pb(currLayer[prev]);
			exposedLayer.pb(currLayer[next]);
			points exposedHull = convexHull(exposedLayer);

			for (auto e: exposedHull) {
				auto it = find(nextLayerRemaining.begin(), nextLayerRemaining.end(), e);
				if (it == nextLayerRemaining.end())
					nextLayerRemaining.pb(e);
			}

			float remainingArea = triArea(currLayer[j], currLayer[prev], currLayer[next]);
			remainingArea -= polArea(exposedHull);
			float finalArea = currConvexArea - remainingArea;

			if (minArea > finalArea && exposedCopy.size() > 0) {
				minArea = finalArea;
				winningIdx = j;
				nextLayerRemainingWinner = nextLayerRemaining;
				exposedLayerWinner = exposedCopy;
			}
		}

		if (winningIdx == -1) break;

		ans.pb(currLayer[winningIdx].id);
		currLayer.erase(currLayer.begin() + winningIdx);
		for (auto e: exposedLayerWinner) {
			currLayer.pb(e);
			
			// auto it = find(nextLayer.begin(), nextLayer.end(), e);
			// if (it != nextLayer.end())
			// 	nextLayer.erase(it);
		}

		for (auto e: nextLayerRemainingWinner) {
			vis[e.id] = 0;
		}

		currLayer = convexHull(currLayer);
		for (auto& e: currLayer) {
			vis[e.id] = 1;
		}

		active.clear();
		for (auto& e: input) {
			if (!vis[e.id]) active.pb(e);
		}

		if (active.size() < 3) {
			nextLayer.clear();
			for (auto e: active) {
				nextLayer.pb(e);
			}
		} else {
			nextLayer = convexHull(active);
		}

		for (auto& e: nextLayer) {
			vis[e.id] = 1;
		}
	}

	// cout << "/////////////First//////////////" << endl;
	// for(auto& e: currLayer) {
	// 	cout << e.id << endl;
	// }

	// cout << "/////////////Next//////////////" << endl;
	// for(auto& e: nextLayer) {
	// 	cout << e.id << endl;
	// }

	while (currLayer.size() > 3) {
		int ls = currLayer.size();
		int winningIdx = -1;
		float currConvexArea = polArea(currLayer);
		if (currConvexArea == 0) break;

		float minArea = inf;

		int j;
		rep(j, ls) {
			int prev;
			int next = (j+1) % ls;

			if (j == 0)
				prev = ls-1;
			else
				prev = j-1;

			float remainingArea = currConvexArea - triArea(currLayer[j], currLayer[prev], currLayer[next]);
			if (minArea > remainingArea) {
				minArea = remainingArea;
				winningIdx = j;
			}
		}
		
		if (winningIdx == -1) break;

		ans.pb(currLayer[winningIdx].id);
		currLayer.erase(currLayer.begin() + winningIdx);
	}

	for (auto& id: ans) {
		if (!removed[id]) {
			cout << id << " ";
			removed[id] = 1;
		}
	}

	for (auto& e: currLayer) {
		if (!removed[e.id]) {
			cout << e.id << " ";
			removed[e.id] = 1;
		}
	}

	for (auto& e: nextLayer) {
		if (!removed[e.id]) {
			cout << e.id << " ";
			removed[e.id] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (removed[i] == 0) cout << i << " "; 
	}
	
	cout << endl;
}

/*
8
2 2
2 6
6 2
6 6
3 3
3 5
5 3
5 5
1

8
2 2
2 6
6 6
6 2
3 3
3 5
5 5
5 3
3

8
3 2
3 8
5 4
5 6
8 3
9 2
9 6
11 7
1

20
2 2
2 3
3 4
4 5
3 8
10 29
11 15
35 46
66 55
9 0
0 0
0 1
0 2
27 34
4 8
6 7
7 8
12 23
34 45
56 67
7
*/