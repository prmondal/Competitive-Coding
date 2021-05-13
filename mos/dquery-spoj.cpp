//Problem Link - https://codeforces.com/contest/221/problem/D

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

//#define TEST

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9+7;
const ll infl = 1e18+7;
const double pi  = acos(-1);
const double eps = 1e-9;
const int maxn = 1e6+5;

int BLOCK_SIZE;

struct Query {
    int l;
    int r;
    int idx;
    int block;

    Query() {}

    Query(int l, int r, int idx): l(l), r(r), idx(idx) {
        block = l / BLOCK_SIZE;
    }

    bool operator<(const Query& o) const {
        if (block != o.block) return block < o.block;
        return r < o.r;
    }
};

void solve() {
    int n, q;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    BLOCK_SIZE = sqrt(n);

    cin >> q;
    vector<Query> queries;
    vector<int> answer(q);

    for (int i = 0; i < q; i++) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        queries.emplace_back(l,r,i);
    }

    sort(queries.begin(), queries.end());

    int currL = 0;
    int currR = -1;
    int ans = 0;
    unordered_map<int, int> freq;

    for (const auto& q: queries) {
        int qL = q.l;
        int qR = q.r;
        int qIdx = q.idx;

        while (currR < qR) {
            currR++;
            ans-=freq.size();
            freq[arr[currR]]++;
            ans+=freq.size();
        }

        while (currR > qR) {
            ans-=freq.size();
            if (freq[arr[currR]]-- == 1) freq.erase(arr[currR]);
            ans+=freq.size();
            currR--;
        } 

        while (currL < qL) {
            ans-=freq.size();
            if (freq[arr[currL]]-- == 1) freq.erase(arr[currL]);
            ans+=freq.size();
            currL++;
        }

        while (currL > qL) {
            currL--;
            ans-=freq.size();
            freq[arr[currL]]++;
            ans+=freq.size();
        }

        answer[qIdx] = ans;
    }

    for (int i = 0; i < q; i++) {
        cout << answer[i] << "\n";
    }
}

int main() {
    fastio;
#ifdef TEST
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
#else
    solve();    
#endif    
}