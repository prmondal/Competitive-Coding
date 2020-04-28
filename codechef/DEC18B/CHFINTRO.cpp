#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, r;
	cin >> n >> r;
	
	for(int i = 0; i < n; i++) {
	    int R;
	    cin >> R;
	    cout << (R < r ? "Bad boi" : "Good boi") << endl;
	}
}
