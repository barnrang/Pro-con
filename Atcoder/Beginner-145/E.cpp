#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>  
#define ll long long

const int MAX = 6001;
const int MAX_CAP = 3000;

using namespace std;
int main() {
    int N, T;
    cin >> N >> T;

    vector<vector<ll> > max_hap;

    for (int i = 0; i < N+1; i++) {
        vector<ll> tmp;
        for (int j = 0; j < MAX; j++) {
            tmp.push_back(0);
        }
        max_hap.push_back(tmp);
    }

    pair<ll, ll> foods[N+1];

    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < MAX; j++) {
            max_hap[i][j] = 0;
        }
    }
    for (int i = 1; i < N+1; i++) {
       int A, B;
       cin >> A >> B;
       foods[i] = make_pair(A,B);
    }

    // cout << T << endl;

    for (int i = 1; i < N+1; i++) 
   { 
       for (int w = 0; w < MAX; w++) 
       {
            if (((w - foods[i].first) >= 0) && ((w - foods[i].first) < T)) {
                max_hap[i][w] = max(foods[i].second + max_hap[i-1][w - foods[i].first],  max_hap[i-1][w]); 
                // cout << max_hap[i][w] << " " << w << " " << max_hap[i-1][w - foods[i].first] << endl;
            } else {
                max_hap[i][w] = max_hap[i-1][w];
            }
            
       } 
   } 


    ll max_result = 0;
   for (int i = 0; i < MAX; i++) {
       if (max_hap[N][i] > max_result) {
           max_result = max_hap[N][i];
       }
   }

   cout << max_result << endl;

}