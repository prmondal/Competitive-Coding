#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    int days[n];
	    int daysInYear = 0;
	    for(int i = 0; i < n; i++) {
	        cin >> days[i];
	        daysInYear += days[i];
	    }
	    
	    int yb, mb, db, yc, mc, dc;
	    cin >> yb >> mb >> db >> yc >> mc >> dc;
	    
	    int noDays1 = 0, noDays2 = 0;
	    noDays1 += yb * daysInYear;
	    noDays2 += yc * daysInYear;
	    for(int m = 1; m < mb; m++) {
	    	noDays1 += days[m - 1];
	    }
	    for(int m = 1; m < mc; m++) {
	    	noDays2 += days[m - 1];
	    }
	    noDays1 += db;
	    noDays2 += dc;
	    int leapYear = 0;
	    for(int i = yb; i < yc; i++) {
	    	if(i % 4 == 0) {
	    		leapYear++;
	    	}
	    }
	    cout << noDays2 - noDays1 + leapYear + 1 << endl;
	}
}
