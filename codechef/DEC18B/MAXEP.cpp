#include <iostream>
using namespace std;
int main() {
    int n, c;
    cin >> n >> c;
    
    if(n <= 1000) {
        for(int i = 1; i <= n; i++) {
            cout << "1 " << i << endl;
            int res;
            cin >> res;
            if(res == 1) {
                //cout << "2" << endl;
                cout << "3 " << i << endl;
                break;
            }
        }
    } else {
        int l = 1, r = n, t = 1000;
        while(l <= r && r-l>c) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            
            cout << "1 " << m1 << endl;
            t--;
            int res;
            cin >> res;
            if(res == 1) {
                cout << "2" << endl;
                t -= c;
                r = m1 - 1;
            } else if(res == 0) {
                cout << "1 " << m2 << endl;
                t--;
                int res2;
                cin >> res2;
                if(res2 == 1) {
                    cout << "2" << endl;
                    t -= c;
                    l = m1 + 1;
                    r = m2 - 1;
                } else if(res2 == 0) {
                    l = m2 + 1;
                }
            }
        }
        if(l <= r) {
            for(int i = l; i <= r; i++) {
                cout << "1 " << i << endl;
                int res;
                cin >> res;
                if(res == 1) {
                    //cout << "2" << endl;
                    cout << "3 " << i << endl;
                    break;
                }
            }
        } else {
            cout << "3 " << l << endl;
        }
    }
}
