#include <iostream>
using namespace std;
#define MAXM 1000000000
int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    cout << "Q" << " " << 0 << " " << 0 << endl;
	    long c1;
	    cin >> c1;
	    if(c1 < 0) break;
	    
	    cout << "Q" << " " << 0 << " " << MAXM << endl;
	    long c2;
	    cin >> c2;
	    if(c2 < 0) break;
	    
	    long k = abs(c1 - c2 + MAXM)/2;
	    cout << "Q" << " " << 0 << " " << k << endl;
	    long x1;
	    cin >> x1;
	    if(x1 < 0) break;
	    
	    long y1 = c1 - x1;
	    
	    cout << "Q" << " " << MAXM << " " << 0 << endl;
	    long c3;
	    cin >> c3;
	    if(c3 < 0) break;
	    
	    long a = MAXM - c3 - x1 + y1;
	    long b = x1 + MAXM - y1 - c2;
	    
	    cout << "A" << " " << x1 << " " << y1 << " " << x1 + a << " " << y1 + b << endl;
	    long res;
	    cin >> res;
	    if(res < 0) break;
	}
}
