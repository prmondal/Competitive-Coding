#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int c = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] != '1') {
			    if(i == 0) {
					if(s[i + 1] != '1') {
						s[i] = '1';
						c++;
					}
				} else if(i == n - 1) {
					if(s[i - 1] != '1') {
						s[i] = '1';
						c++;
					}
				} else {
					if(s[i - 1] != '1' && s[i + 1] != '1') {
						s[i] = '1';
						c++;
					}
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}
