#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>  
#define ll long long
 
ll mod = 1000000007;
 
int MAX = 1000000;
 
ll facs[1000000];
ll inv_fac_mod[1000000];  
 
using namespace std;
 
ll true_mod(ll x){
    return (x + mod) % mod;
}
 
int ipow(int base, int exp)
{
    if (exp == 1) return base;
    if (exp % 2 == 1) {
        ll result = ipow(base, exp / 2);
        result *= true_mod(result * base);
        result = true_mod(result);
        return result;
    } else {
        ll result = ipow(base, exp / 2);
        result *= true_mod(result);
        result = true_mod(result);
        return result;
    }
}
 
int main () {
    ll prod = 1;
    for(int i = 0; i < MAX; i++) {
        if(i == 0) facs[0] = 1;
        else {
            prod *= i;
            prod = (prod + mod) % mod;
            facs[i] = prod;
        }
    }
 
    for (int i = 0; i < MAX; i++) {
        inv_fac_mod[i] = ipow(facs[i], mod - 2);
    }
 
    ll x,y;
    cin >> x >> y;
 
    ll tx = 2 * x - y;
    ll ty = -x + 2 * y;
    if ((tx % 3 != 0) || (ty % 3 != 0)) {
        cout << 0 << endl;
        return 0;
    }

    if ((tx < 0) || (ty < 0)) {
        cout << 0 << endl;
        return 0;
    }
 
    tx /= 3; ty /= 3;
 
    cout << true_mod(true_mod(facs[tx+ty] * inv_fac_mod[tx]) * inv_fac_mod[ty]) << endl;
 
    return 0;
}