#include <bits/stdc++.h>

using namespace std;

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

struct Tree {
    vector<ll> bit;
    vector<int> entr, ext;
    int timer = 1;
    vector<vector<int>> adj;
    int n;

    void bitUpdate(int idx, ll val) {
        while(idx <= 2*n) {
            bit[idx]+=val;
            idx += (idx & -idx);
        }
    }

    ll bitQuery(int idx) {
        ll ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= (idx & -idx);
        }

        return ans;
    }

    void dfs(int u, int p) {
        entr[u] = timer++;
        for (auto& e: adj[u]) {
            if (e != p) {
                dfs(e, u);
            }
        }
        ext[u] = timer++;
    }

    void update(int idx, ll val) {
        bitUpdate(entr[idx], val);
        bitUpdate(ext[idx], -val);
    }

    bool isAncestor(int u, int v) {
        return entr[u] <= entr[v] && ext[u] >= ext[v];
    }

    ll rangeQuery(int u, int v) {
        if (!isAncestor(u,v)) return -1;
        return bitQuery(entr[v]) - bitQuery(entr[u]-1);
    }

    Tree(vector<int>& v, vector<ll>& a) {
        n = v.size();
        adj = vector<vector<int>>(n);

        int i;
        rep(i,n) {
            if (v[i] != -1) {
                adj[i].pb(v[i]);
                adj[v[i]].pb(i);
            }
        }

        entr = vector<int>(n);
        ext = vector<int>(n);

        dfs(0, -1);
        
        bit = vector<ll>(2*n+1, 0);

        rep(i,n) {
            bitUpdate(entr[i], a[i]);
            bitUpdate(ext[i], -a[i]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,q;
	cin >> n >> q;
	vector<ll> h(n+1, 0), a(n+1, 0);

	int i;
	f(i,1,n+1) {
		cin >> h[i];
	}

	f(i,1,n+1) {
		cin >> a[i];
	}
    
    vector<int> right(n+1), left(n+1);
    right[0] = -1;
    left[0] = -1;

    stack<int> s;
    i = 1;

    while (i <= n) {
        while(!s.empty() && h[s.top()] <= h[i]) {
            s.pop();
        }

        if (s.empty())
            right[i] = 0;
        else
            right[i] = s.top();

        s.push(i++);
    }

    while(!s.empty()) {
        s.pop();
    }

    i = n;
    while (i >= 1) {
        while(!s.empty() && h[s.top()] <= h[i]) {
            s.pop();
        }

        if (s.empty())
            left[i] = 0;
        else
            left[i] = s.top();
            
        s.push(i--);
    }

    Tree t1(right, a);
    Tree t2(left, a);

	rep(i,q) {
		int t;
		cin >> t;

		if (t == 1) {
			int id;
            ll val;
			cin >> id >> val;
            t1.update(id,val-a[id]);
            t2.update(id,val-a[id]);
            a[id]=val;
		} else {
			int s,e;
			cin >> s >> e;
            if (s < e) {
                cout << t1.rangeQuery(s,e) << "\n";
            } else {
                cout << t2.rangeQuery(s,e) << "\n";
            }
		}
	}
}
