#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

bool isSorted(const vector<int> v) {
    for(int i = 1; i < v.size(); i++) {
        if(v[i] < v[i-1]) return false;
    }

    return true;
}

ull getDecimal(const vector<int> v) {
    string ans = "";

    for(auto i: v) {
        ans += to_string(i);
    }

    return stoll(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ull n;
        int d;

        cin >> n >> d;
        vector<int> v;

        while(n > 0) {
            v.push_back(n%10);
            n = n/10;
        }
        
        int no = v.size();
        reverse(v.begin(), v.end());
        v.erase(remove_if(v.begin(), v.end(), [=](int i) { return i > d;}), v.end());

        int nn = v.size();
        
        if(nn > 0) {
            ull ans = getDecimal(v);

            while(!isSorted(v)) {
                vector<int> winner;
        
                for(int i = 0; i < nn; i++) {
                    vector<int> test;
        
                    for(int j = 0; j < nn; j++) {
                        if(j == i) continue;
        
                        test.push_back(v[j]);
                    }
        
                    test.push_back(d);
                    ull testDecimal = getDecimal(test);
        
                    if(ans > testDecimal) {
                        ans = testDecimal;
                        winner = test;
                    }
                }
        
                v = winner;
            }   
        }
        
        int nf = v.size();
        for(int i = 1; i <= no-nf; i++) v.push_back(d);

        cout << getDecimal(v) << endl;
    }
}