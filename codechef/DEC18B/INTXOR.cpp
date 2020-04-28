#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		int m = n % 4;
		if(m == 1) {//n=5
			int r1, r2, r3, r4, r5;
			cout << "1 1 2 3" << endl;
			cin >> r1;
			if(r1 == - 1) return 0;
			cout << "1 1 3 4" << endl;
			cin >> r2;
			if(r2 == - 1) return 0;
			cout << "1 1 4 5" << endl;
			cin >> r3;
			if(r3 == - 1) return 0;
			cout << "1 2 3 5" << endl;
			cin >> r4;
			if(r4 == - 1) return 0;
			cout << "1 2 4 5" << endl;
			cin >> r5;
			if(r5 == - 1) return 0;
			arr[0] = r2 ^ r4 ^ r5;
			arr[1] = r2 ^ r3 ^ r4;
			arr[2] = r1 ^ r3 ^ r5;
			arr[3] = r1 ^ r3 ^ r4;
			arr[4] = r1 ^ r2 ^ r5;
		} else if(m == 2) {//n = 6
			int r1, r2, r3, r4, r5, r6;
			cout << "1 1 2 3" << endl;
			cin >> r1;
			if(r1 == - 1) return 0;
			cout << "1 1 4 5" << endl;
			cin >> r2;
			if(r2 == - 1) return 0;
			cout << "1 1 4 6" << endl;
			cin >> r3;
			if(r3 == - 1) return 0;
			cout << "1 2 3 4" << endl;
			cin >> r4;
			if(r4 == - 1) return 0;
			cout << "1 2 5 6" << endl;
			cin >> r5;
			if(r5 == - 1) return 0;
			cout << "1 3 5 6" << endl;
			cin >> r6;
			if(r6 == - 1) return 0;
			arr[0] = r1 ^ r5 ^ r6;
			arr[1] = r2 ^ r3 ^ r5;
			arr[2] = r2 ^ r3 ^ r6;
			arr[3] = r4 ^ r5 ^ r6;
			arr[4] = r1 ^ r2 ^ r4;
			arr[5] = r1 ^ r3 ^ r4;
		} else if(m == 3) {//n = 7
			int r1, r2, r3, r4, r5, r6, r7;
			cout << "1 1 3 5" << endl;
			cin >> r1;
			if(r1 == - 1) return 0;
			cout << "1 1 3 6" << endl;
			cin >> r2;
			if(r2 == - 1) return 0;
			cout << "1 1 4 6" << endl;
			cin >> r3;
			if(r3 == - 1) return 0;
			cout << "1 2 4 6" << endl;
			cin >> r4;
			if(r4 == - 1) return 0;
			cout << "1 2 4 7" << endl;
			cin >> r5;
			if(r5 == - 1) return 0;
			cout << "1 2 5 7" << endl;
			cin >> r6;
			if(r6 == - 1) return 0;
			cout << "1 3 5 7" << endl;
			cin >> r7;
			if(r7 == - 1) return 0;
			arr[0] = r1 ^ r2 ^ r3 ^ r5 ^ r6;
			arr[1] = r1 ^ r2 ^ r4 ^ r5 ^ r6;
			arr[2] = r1 ^ r2 ^ r4 ^ r5 ^ r7;
			arr[3] = r1 ^ r3 ^ r4 ^ r5 ^ r7;
			arr[4] = r1 ^ r3 ^ r4 ^ r6 ^ r7;
			arr[5] = r2 ^ r3 ^ r4 ^ r6 ^ r7;
			arr[6] = r2 ^ r3 ^ r5 ^ r6 ^ r7;
		}
		
		int i = (m == 0) ? 1 : m + 5;
		while(i <= n) {
			int a = i, b = i + 1, c = i + 2, d = i + 3;
			int r1, r2, r3, r4;
			cout << "1 " << a << " " << b << " " << c << endl;
			cin >> r1;
			if(r1 == - 1) return 0;
			cout << "1 " << a << " " << b << " " << d << endl;
			cin >> r2;
            if(r2 == - 1) return 0;
            
			cout << "1 " << a << " " << c << " " << d << endl;
			cin >> r3;
			if(r3 == - 1) return 0;
			cout << "1 " << b << " " << c << " " << d << endl;
			cin >> r4;
			if(r4 == - 1) return 0;
			arr[a-1] = r1 ^ r2 ^ r3;
			arr[b-1] = r1 ^ r2 ^ r4;
			arr[c-1] = r1 ^ r3 ^ r4;
			arr[d-1] = r2 ^ r3 ^ r4;
			i += 4;
		}
		cout << "2 ";
		for(int j = 0; j < n; j++) {
			if(j == n - 1) {
				cout << arr[j] << endl;
			} else {
				cout << arr[j] << " ";
			}
		}
		int r;
		cin >> r;
		
		if(r == -1) return 0;
	}
}
