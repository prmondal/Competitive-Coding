#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int mid;
    int a, b;
} Triangle;

const int MAXN = 2e6;
int BIT[MAXN+1] = {0};

int query(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += BIT[idx];
        idx -= (idx & -idx);
    }

    return ans;
}

void update(int idx, int v) {
    while(idx <= MAXN) {
        BIT[idx] += v;
        idx += (idx & -idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        pair<int,int> ps[n];
        for (int i = 1; i <= n; i++) {
            int x,y;
            cin>>x>>y;
            ps[i-1] = {2*x,2*y};
        }

        sort(ps, ps+n);

        pair<Triangle, int> qs[q];
        for (int i = 1; i <= q; i++) {
            int l,r;
            cin>>l>>r;

            Triangle t;
            t.a = 2*l, t.b = 2*r, t.mid = l+r;
            qs[i-1] = {t, i};
        }

        sort(qs, qs+q, [](const pair<Triangle, int>& t1, const pair<Triangle, int>& t2) {
            return t1.first.mid < t2.first.mid;
        });

        int ans[q+1] = {0};
        
        // left triangle
        int j = 0;
        int currPntIdx = 0;
        while (j < q) {
            auto currTri = qs[j].first;
            int qidx = qs[j].second;

            while(ps[currPntIdx].first <= currTri.mid && currPntIdx < n) {
                int z = ps[currPntIdx].first - ps[currPntIdx].second;
                if (z >= 0) update(z, 1);
                
                currPntIdx++;
            }

            ans[qidx] += query(MAXN) - query(currTri.a-1);
            j++;
        }

        memset(BIT, 0, sizeof BIT);

        // right triangle
        j = q-1;
        currPntIdx = n-1;
        while(j >= 0) {
            auto currTri = qs[j].first;
            int qidx = qs[j].second;

            while(ps[currPntIdx].first > currTri.mid && currPntIdx >= 0) {
                int z = ps[currPntIdx].first + ps[currPntIdx].second;
                update(z, 1);
                currPntIdx--;
            }

            ans[qidx] += query(currTri.b);
            j--;
        }

        for (int i = 1; i <= q; i++) {
            cout << ans[i] << endl;
        }
    }
}

/*
1
6 3
1 2
14 7
6 3
8 7
11 10
14 2
0 10
2 22
11 17
*/