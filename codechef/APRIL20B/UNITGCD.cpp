#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        int i;
        vector<vector<int>> res;
        if (n == 1) res.push_back({1});
        
        for (i = 2; i < n; i+=2) {
            if(i == 2)
                res.push_back({1, i,i+1});
            else
                res.push_back({i,i+1});
        }

        if (i == n) res.push_back({i});
        printf("%d\n", (int)res.size());

        for (auto e: res) {
            int size = e.size();
            if (size > 0) {
                printf("%d ", size);
                for(int i = 0; i < size; i++) {
                    if(i == size-1)
                        printf("%d\n", e[i]);
                    else
                        printf("%d ", e[i]);
                }
            } 
        }
    }
}
