#include <bits/stdc++.h>
using namespace std; 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, s;
        cin >> n >> x >> s;
        
        int cPos = x;
        
        while(s--) {
            int i, j;
            cin >> i >> j;
            
            if(i == cPos) {
                cPos = j;
            } else if(j == cPos) {
                cPos = i;
            } 
        }
        
        cout << cPos << endl;
    }
}
