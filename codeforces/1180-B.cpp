#include <bits/stdc++.h>
using namespace std;

/*
	case 1: product is negative, do op on odd number of positive values
	case 2: product is non-negative, do op on evn number of positive values
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a[n];
    cin >> n;
    
    int cn = 0; // #-ve values
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        if (a[i] < 0) cn++;
    }
    
    int t = n - cn;
    
    if (cn & 1) {
        if (!(t & 1)) t--;
    } else {
        if (t & 1) t--;
    }
    
    int j = 0;
    int i = 0;
    
    while (i < n) {
        if(a[i] >= 0 && j < t) {
            a[i] = ~a[i];
            j++;
        }
        
        cout << a[i] << " ";
        i++;
    }
}