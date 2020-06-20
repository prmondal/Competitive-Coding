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
#define inf (1000*1000*1000+5)
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    string s = "";

    ll l = 1;
    ll h = n;

    while (s != "E") {
    	ll y = l + (h-l)/2;

    	cout << y << endl;
    	cin >> s;

    	if (s == "E") {
    		cout << y << endl;
    		return 0;
    	}

    	string s1;
    	cout << y << endl;
    	cin >> s1;

    	if (s1 == "E") {
    		cout << y << endl;
    		return 0;
    	}

    	if (s == s1) {
    		if (s == "L") {
    			h = y-1;
    		} else if (s == "G") {
    			l = y+1;
    		}
    	} else {
    		string s2;
    		cout << y+1 << endl;
    		cin >> s2;

    		if (s2 == "E") {
				cout << y+1 << endl;
    			return 0;
			}

			if (s1 == s2) {
				if (s1 == "L") {
					h = y;
				} else {
					l = y+2;
				}
			} else {
				if (s == s2) {
					string s3;
					cout << y-1 << endl;
					cin >> s3;

					if (s3 == "E") {
						cout << y-1 << endl;
    					return 0;
					}

					if (s3 == "L") {
						if (s != s3) {
							l = y-2;
						} else {
							h = y;
						}
					} else {
						if (s != s3) {
							h = y;
						} else {
							l = y-2;
						}
					}
				}
			}
    	}
    }
}
