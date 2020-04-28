#include <iostream>
using namespace std;
long bin(long n, long k) {
    if(k > n - k) {
    	k = n - k;
    }
    long res = 1;
    for(int i = 0; i < k; i++) {
    	res *= (n - i);
    	res /= (i + 1);
    }
    return res;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		long n, k;
		cin >> n >> k;
        
        if(n == k) cout << 1 << endl;
        else {
            n = n - k;
		    cout << bin(n+k-1, n) << endl;
        }
	}
}
