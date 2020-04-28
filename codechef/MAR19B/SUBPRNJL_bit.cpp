#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 2000

int BIT[MAX_SIZE + 1];

int query(int x) {
    int sum = 0;

    while(x > 0) {
        sum += BIT[x];
        x -= x&-x;
    }

    return sum;
}

int update(int x, int v) {
    while(x <= MAX_SIZE) {
        BIT[x] += v;
        x += x&-x;
    }
}

int kthSmallest(int k) {
    int l = 1;
    int r = MAX_SIZE;

    while(l < r) {
        int mid = (l+r)/2;

        if(query(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            memset(BIT, 0, sizeof(BIT));
            
            int l = 1;
            while(l <= n-i+1) { 
                int m = ceil((double)k/l);
                int kk = k%m == 0 ? k/m : k/m+1;
                update(a[i+l-2], 1);
                
                int x = kthSmallest(kk);
                int f = query(x) - query(x-1);
                int c = query(f) - query(f-1);
                if(c > 0) ans++;
                
                l++;
            }
        }

        cout << ans << endl;
    }
}
