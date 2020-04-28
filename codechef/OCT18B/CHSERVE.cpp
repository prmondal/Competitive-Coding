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
    	long p1, p2, k;
    	cin >> p1 >> p2 >> k;
    	long d = ((p1+p2)/k)%2;
    	
    	if(d == 0) cout << "CHEF" <<endl;
    	else cout << "COOK" << endl;
    }
}
