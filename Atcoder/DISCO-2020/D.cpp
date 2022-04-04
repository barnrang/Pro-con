#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>  
#define ll long long

using namespace std;

pair<ll, ll> count_reduce(int x, ll n) {
    ll count = 0;
    if (n == 1) {
        return make_pair(0, x);
    }
    pair<ll, ll> result = count_reduce(x, n/2);
    ll num = result.first; ll left = result.second;
    count += 2 * num;
    if (left >= 5){
        count += 2;
        left = (2 * left - 9) ;
    }
    else {
        count += 1;
        left = 2 * left;
    }

    if (n & 1 == 1)
    {
        if(left + x > 9) {
            count += 2;
            left = (left + x) - 9;
        } else {
            left = left + x;
            count += 1;
        }
    }
        
    return make_pair(count, left);
}

int main() {
    int M;
    cin >> M;
    ll D[M], C[M];
    ll out[M];
    for (int i = 0; i < M; i++) {
        ll d,c;
        cin >> d >> c;
        D[i] = d;C[i] = c; 
    } 

    ll count = 0;
    for (int i = 0; i < M; i++) {
        pair<ll, ll> result = count_reduce(D[i],C[i]);
        count += result.first;
        out[i] = result.second;
    }

    ll lh = out[0];
    for (int i = 1; i < M; i++) {
        ll rh = out[i];
        if ((lh + rh) > 9) {
            count += 2;
            lh = (lh + rh - 9);
        }
        else{
            lh = lh + rh;
            count += 1;
        }
    }
    cout << count << endl;
}