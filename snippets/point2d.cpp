#pragma GCC optimize("Ofast")
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
#define inf 0x3f3f3f3f
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

const int PI = acos(-1);

struct point {
	int x, y;
    ll id;

    point() {}
	point(int x, int y, int id=-1): x(x),y(y),id(id) {}

	point operator-(const point& p) const {
		return point({x-p.x, y-p.y});
	}

    point operator+(const point& p) const {
		return point({x+p.x, y+p.y});
	}

    point operator*(const int m) const {
		return point({x*m, y*m});
	}

    bool operator==(const point& p) const {
		return p.x==x && p.y==y;
	}

    bool operator!=(const point& p) const {
		return p.x!=x || p.y!=y;
	}

    double len() {
        return sqrt(x*x + y*y);
    }

    void normalized() {
        double l = len();
        x /= l;
        y /= l;
    }

    point normal() {
        return {-y, x};
    }

    const int key() const {
        return (int) x | (int)y<<16;
    }
};

int cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

int cross(point p1, point p2, point p3) {
	point v1 = p2-p1;
	point v2 = p3-p2;
	return cross(v1, v2);
}

int dot(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

int dist_sq(const point& p1, const point& p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int orientation(const point& a, const point& b, const point& c) {
    int o = cross(a,b,c);
    if (o == 0) return 0;
    return o > 0 ? 1 : 2;
}

bool intersects(const point& a, const point& b, const point& c, const point& d) {
    int o1 = orientation(a,b,c);
    int o2 = orientation(a,b,d);
    int o3 = orientation(c,d,a);
    int o4 = orientation(c,d,b);
    
    return o1 != o2 && o3 != o4;
}

const point segmentIntersection(const point& a, const point& b, const point& c, const point& d) {
    int o1 = orientation(a,b,c);
    int o2 = orientation(a,b,d);
    int o3 = orientation(c,d,a);
    int o4 = orientation(c,d,b);
    
    if (o1 != o2 && o3 != o4) {
        point d1 = b-a;
        point d2 = c-d;
        d1.normalized();
        d2.normalized();

        return a + d1 * (cross(c - a, d2) / cross(d1, d2));
    }

    return {inf,inf};
}