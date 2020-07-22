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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,q;
	cin >> n >> q;

	ll h[n];
	ll a[n];

	int i;
	rep(i,n) {
		cin >> h[i];
	}

	rep(i,n) {
		cin >> a[i];
	}

	rep(i,q) {
		int t;
		cin >> t;

		if (t == 1) {
			int id;
            ll k;
			cin >> id >> k;
            id--;
			a[id] = k;
		} else {
			int s,e;
			cin >> s >> e;
			s--;
			e--;

			if (s == e) {
				cout << a[s] << endl;
				continue;
			}

            ll ans = 0;
            bool possible = true;

            if (s < e) {
                int j = s;
                ans += a[s];
                
                while (j < e) {
                    ll mx = 0;
                    int jumpIdx = -1;

                    for (int k = j+1; k <= e; k++) {
                        if (mx <= h[k]) {
                            mx = h[k];
                            jumpIdx = k;
                        }
                    }

                    if (mx >= h[j]) {
                        possible = false;
                        break;
                    }

                    ans += a[jumpIdx];
                    j = jumpIdx;
                }
            } else {
                int j = s;
                ans += a[s];
                
                while (j > e) {
                    ll mx = 0;
                    int jumpIdx = -1;

                    for (int k = j-1; k >= e; k--) {
                        if (mx <= h[k]) {
                            mx = h[k];
                            jumpIdx = k;
                        }
                    }

                    if (mx >= h[j]) {
                        possible = false;
                        break;
                    }
                    
                    ans += a[jumpIdx];
                    j = jumpIdx;
                }
            }

            if (!possible) {
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
		}
	}
}
