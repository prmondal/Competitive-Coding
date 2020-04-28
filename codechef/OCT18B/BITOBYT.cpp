#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int t;
    cin >> t;
    
    while(t-->0){
        long long i = 1, j = 0, k = 0;
        
        int n;
        cin >> n;
        
        int d = (n-1)%26;
        i = pow(2, (n-1)/26);
        
        if(d >= 10) {
            k = i;
            i = 0;
            j = 0;
        } else if(d >= 2 && d < 10) {
            j = i;
            i = 0;
            k = 0;
        }
        
        cout << i << " " << j << " " << k << endl;
    }
}
