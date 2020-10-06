#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define bit(x,i) (x&(1<<i))
#define umapi unordered_map<int,int>
#define mapi map<int,int>
#define useti unordered_set<int>
#define seti set<int>
#define pqmin priority_queue<int>
#define pqmax priority_queue<int,vi,greater<int>>
#define coutp(i) cout << fixed << setprecision(i)
#define debug(x) cerr << "[ " << #x << " - " << x << " ]" << endl

const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;

const int nax = 1e9+7;

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n%i == 0) return false;
    }

    return true;
}

void divisors(int n, vi& v1, vi& v2) {
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i))
                v1.pb(i);
            else
                v2.pb(i);

            if (n != i*i) {
                int k = n/i;
                if (isPrime(k)) {
                    v1.pb(k);
                } else
                    v2.pb(k);
            }
        }
    }

    v2.pb(n);
}

void solve() {
    int n;
    cin >> n;

    vi v1, v2;
    divisors(n, v1, v2);
    sort(all(v2));

    // for(auto e: v1) cout << e << " ";
    // cout << endl;
    // for(auto e: v2) cout << e << " ";
    // cout << endl;

    const int k1 = (int) v1.size();
    const int k2 = (int) v2.size();
    bool extracted[k2];
    rep(i,k2) extracted[i] = false;

    if (k1 == 2 && k2 == 1) {
        cout << v1[0] << " " << v2[0] << " " << v1[1] << endl;
        cout << 1 << endl;
    } else {
        vi order;

        map<int, vi> m;

        rep(i,k1) {
            int nxt = (i+1) % k1;
            if (nxt == 0 && k1 == 2) {
                m[v1[i]] = vi();
                break;
            }

            int adjProduct = v1[i]*v1[nxt];

            int idx = lower_bound(all(v2), adjProduct) - v2.begin();
            extracted[idx] = true;
            m[v1[i]].insert(m[v1[i]].begin(), adjProduct);
        }

        // for(auto e: m) {
        //     cout << e.first << " - ";
        //     for (auto ee: e.second) cout << ee << " ";
        // }

        // cout << endl;

        rep(i,k1) {
            rep(j,k2) {
                if (extracted[j]) continue;

                if (v2[j] % v1[i] == 0) {
                    m[v1[i]].insert(m[v1[i]].begin(), v2[j]);
                    extracted[j] = true;
                }
            }
        }
        
        int ans = 1;
        
        // if there are two prime factors try to insert a multiple of last prime which is also divisible by first prime at the end
        // if not satisfied try to insert a multiple of first prime which is also divisible by last prime at the end
        if (k1 == 2) {
            vi& v = m[v1[k1-1]];
            vector<int>::iterator it;
            int targetVal;

            for (it = v.begin(); it != v.end(); it++) {
                if (*it % v1[0] == 0) {
                    targetVal = *it;
                    break;
                }
            }

            if (it != v.end()) {
                v.erase(it);
                v.pb(targetVal);
                ans = 0;
            } else {
                vi& v = m[v1[0]];
                vector<int>::iterator it;
                int targetVal;

                for (it = v.begin(); it != v.end(); it++) {
                    if (*it % v1[k1-1] == 0) {
                        targetVal = *it;
                        break;
                    }
                }

                if (it != v.end()) {
                    v.erase(it);
                    m[v1[k1-1]].pb(targetVal);
                    ans = 0;
                }
            }
        }
        
        for(auto& e: m) {
            cout << e.first << " ";
            for (auto& ee: e.second) cout << ee << " ";
        }
        cout << endl;

        if (k1 == 2) {
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}