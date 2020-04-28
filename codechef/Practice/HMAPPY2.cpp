#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    long long int n,a,b,k;
	    cin >> n >> a >> b >> k;
	    
	    long long int i = n/a;
	    long long int j = n/b;
	    long long int m = (a*b)/gcd(a,b);
	    long long int l = 2*(n/m);
	    
	    long long int c = i+j-l;
	    cout << (c >= k ? "Win" : "Lose") << endl;
	}
}
