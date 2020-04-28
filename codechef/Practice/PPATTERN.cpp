#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n][n];
        int i = 1;
        for(int c = 1; c <= n; c++) {
            int k = 0;
            for(int j = c; j >= 1; j--) {
                a[k++][j-1] = i++;
            }
        }
        for(int r = 1; r < n; r++) {
            int k = r;
            for(int j = n; j >= 1 && k < n; j--) {
                a[k++][j-1] = i++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j==n-1) cout << a[i][j];
                else cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
