// CPP program to illustrate 
// gcd function of C++ STL 
#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>  
#define ll long long
  
using namespace std; 
vector<ll> dv;

int main() {
    ll A,B;
    cin >> A >> B;
    ll D = __gcd(A,B);
    ll ori_D = D;
    double mid = sqrt(D);
    ll count = 0;
    dv.push_back(1);
    // cout << D << endl;
    if (D > 1){
        for (ll x = 2; x <= mid+1; x++) {
            // cout << x << ' ' << D << endl;
            if (ori_D % x == 0) dv.push_back(x);
            if (D % x == 0) {
                count++;
                while(D % x == 0){
                    D /= x;
                }
                
            }
        }
        if (D != 1) {
            for (int i = dv.size() - 1; i >= 0; --i) {
                ll oppo_dv = ori_D / dv[i];
                if (D % oppo_dv == 0) {
                    count++;
                    while(D % oppo_dv == 0){
                        D /= oppo_dv;
                    }
                }
                if (D == 1) break;    
            }
        }
    }

    cout << count + 1 << endl;

}