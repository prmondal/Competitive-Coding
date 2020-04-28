#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        long n,q;
        scanf("%ld%ld",&n,&q);

        long a[n];
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; i++) {
            scanf("%ld", &a[i]);
            if (__builtin_parity(a[i])) odd++;
            else even++;
        }

        while(q--) {
            int p;
            scanf("%d", &p);

            if (__builtin_parity(p) == 1) {
                printf("%d %d\n", odd, even);   
            } else {
                printf("%d %d\n", even, odd);
            }
        }
    }
}
