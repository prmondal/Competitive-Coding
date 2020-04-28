#include <iostream>
#include <sstream>
using namespace std;
int main() {
    int t;
    cin >> t;cin.ignore();
    
    while(t--) {
        string str;
        getline(cin,str);
        stringstream ss(str);
        string token;
        bool found = false;
        
        while(getline(ss, token, ' ')) {
            if(token == "not") {
                found = true;
                break;
            }
        }
        
        if(found) {
            cout << "Real Fancy" << endl;
        } else {
            cout << "regularly fancy" << endl;
        }
    }
}
