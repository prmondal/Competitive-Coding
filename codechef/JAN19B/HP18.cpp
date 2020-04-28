#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    long n, a, b;
	    cin >> n >> a >> b;
	    
	    long ca = 0, cb = 0, cc = 0;
	    long arr[n];
	    
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	        
	        if(arr[i] % a == 0) {
	            ca++;
	        }
	        
	        if(arr[i] % b == 0) {
	            cb++;
	        }
	        
	        if(arr[i] % (a*b) == 0) {
	            cc++;
	        }
	    }
	    
	    if(a == b) {
	        cout << "BOB" << endl;
	    } else {
	        if(b % a == 0) {
	            cout << "BOB" << endl; 
	        } else if(a % b == 0) {
	            cout << "ALICE" << endl;
	        } else {
	            if(cc > 0) {
	                cb -= cc;
	            }
	            
	            if(ca > cb) {
	                cout << "BOB" << endl;
	            } else {
	                cout << "ALICE" << endl;
	            }
	        }
	    }
	}
}
