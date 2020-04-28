#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        long n;
        cin>>n;

        long a[n];
        long ans = 0;

        vector<long> bools;
        vector<int> fours;
        vector<long> evens;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            
            if (a[i] % 2 != 0) {
                bools.push_back(0);
            } else {
                evens.push_back(i);
                bools.push_back(1);
                if (a[i]%4==0) fours.push_back(i);
            }
        }

        int sum = bools[0];
        int i = 0, j = 0;
        long count1 = 0;
        int k = 2;

        while (i < n && j < n) {
            if(sum < k) {
                j++;

                if (j >= i) {
                    count1 += j-i;
                }

                if (j < n) {
                    sum += bools[j];
                }
            } else {
                sum -= bools[i];
                i++;
            }
        }
        
        ans += n*(n+1)/2 - count1;

        long count2 = 0;
        for(auto idx: fours) {
            int lc = 1;
            int rc = 1;
            int l = idx-1;
            int r = idx+1;

            while(l >= 0) {
                if (a[l]%2 != 0) {
                    l--;
                    lc++;
                } else 
                    break; 
            }

            while(r < n) {
                if (a[r]%2 != 0) { 
                    r++;
                    rc++;
                } else
                    break;
            }

            count2 += lc*rc;
        }
        
        ans += count2;

        long count3 = 0;
        int s = evens.size();

        if (s == 0) {
            count3 += n*(n+1)/2;
        } else {
            long gap = 0;
            for(int i = 0; i < s; i++) {
                if (i==0) {
                    count3 += evens[i]*(evens[i]+1)/2;
                } else {
                    gap = evens[i] - evens[i-1] - 1;
                    count3 += gap*(gap+1)/2;
                }
            }

            if (evens[s-1] < n-1) {
                gap = n - evens[s-1] - 1;
                count3 += gap*(gap+1)/2;
            }
        }
        
        ans += count3;
        cout << ans << endl;
    }
}
