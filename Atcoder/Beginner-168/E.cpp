#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>
// #include <algorithm>    
#define ll long long
#define MOD 1000000007
#define MAX_FLOAT 1e20

ll mod(ll x){
    return (x+MOD) % MOD;
}
  
using namespace std; 

int main(){
    ll n;
    cin >> n;
    float ratio[200000];
    for (int i = 0; i < n; i++) {
        float a,b;
        cin >> a >> b;
        if (b == 0) ratio[i] = MAX_FLOAT;
        else ratio[i] = a / b;
    }

    ll dp[200000];
    dp[0] = 1;

    make_heap(ratio, ratio+n);

    return 0;
}