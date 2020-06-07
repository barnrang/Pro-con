#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

ll dp1[2019];
ll dp2[2019];

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 2019; i++) {
        dp1[i] = 0; dp2[i] = 0;
    }

    dp1[0] = 1;

    int su = 0;

    for (int i = 0; i < s.length(); i++) {
        // cout << (int)(s[i] - '0') << endl;
        for (int j = 0; j < 2019; j++) {
            int idx = (10 * j + s[i] - '0') % 2019;
            dp2[idx] += dp1[j];
        }

        for (int j = 0; j < 2019; j++) {
            dp1[j] = dp2[j];
            
            dp2[j] = 0;
            
        }
        su += dp1[0];
        dp1[0]++;

        // cout << dp1[0] << endl;
    }

    cout << su << endl;
}