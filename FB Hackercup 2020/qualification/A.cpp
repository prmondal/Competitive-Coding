#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define f(i,j,n) for(int i=j;i<n;i++)
#define rep(i,n) f(i,0,n)
#define repr(i,n) for(int i=n-1;i>=0;i--)
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
#define uniq(v) v.erase(v.unique(all(v)), v.end())
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

int main() {
    int t;
    cin>>t;

    ofstream f;
    f.open ("A_output.txt");

    int c = 1;

    while(t--) {
        int n;
        cin >> n;

        string I, O;
        cin >> I >> O;

        char ans[n][n];
        int i,j;

        rep(i,n){
            rep(j,n) {
                ans[i][j] = (i == j ? 'Y' : 'N');
            }
        }

        rep(i,n) {
            for (int j = i + 1; j < n; j++) {
                if (O[i] == 'Y') {
                    if (I[j] == 'Y' && O[j-1] == 'Y')
                        ans[i][j] = 'Y';
                    else
                        break;
                }
            }
        }

        rep(i,n){
            for (int j = i - 1; j >= 0; j--) {
                if (O[i] == 'Y') {
                    if (I[j] == 'Y' && O[j+1] == 'Y')
                        ans[i][j] = 'Y';
                    else
                        break;
                }
            }
        }
        
        f << "Case #" << c << ":" << endl;

        rep(i,n){
            rep(j,n) {
                f << ans[i][j];
            }

            f << endl;
        }

        c++;
    }

    f.close();
}

// YNNYY
// YYYNY

//    1 2 3 4 5
//  1 y n n n n
//  2 y y n n n
//  3 n n y y n
//  4 n n n y n
//  5 n n n y y