#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

#define ll long long
#define sum_cake tuple<ll, int, int, int>

bool comp(sum_cake x, sum_cake y){
    ll first_sum = get<0>(x);
    ll sec_sum = get<0>(y);
    return first_sum < sec_sum;
}

ll to_use_idx(int x, int y, int z){
    return 1000000 * x + 1000 * y + z;
}

int main(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    ll A[x], B[y], C[z];
    
    for(int i = 0; i < x; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < y; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < z; i++) {
        cin >> C[i];
    }
    sort(A, A+x, greater<ll>()); 
    sort(B, B+x, greater<ll>()); 
    sort(C, C+x, greater<ll>()); 

    priority_queue<sum_cake, vector<sum_cake>, decltype(&comp)> q(comp);
    set<ll> used_idx;

    sum_cake first_set = make_tuple(A[0] + B[0] + C[0], 0, 0, 0);
    vector<ll> sum_list;
    q.push(first_set);
    used_idx.insert(0);

    for (int i = 0; i < k; i++) {
        auto larg = q.top();
        sum_list.push_back(get<0>(larg));
        int a=get<1>(larg), b=get<2>(larg), c=get<3>(larg);
        q.pop();
        if ((a + 1 < x) && (used_idx.count(to_use_idx(a+1,b,c)) == 0)) {q.push(make_tuple(A[a+1] + B[b] + C[c], a+1, b, c)); used_idx.insert(to_use_idx(a+1, b, c));}
        if ((b + 1 < x) && (used_idx.count(to_use_idx(a,b+1,c)) == 0)) {q.push(make_tuple(A[a] + B[b+1] + C[c], a, b+1, c)); used_idx.insert(to_use_idx(a, b+1, c));}
        if ((c + 1 < x) && (used_idx.count(to_use_idx(a,b,c+1)) == 0)) {q.push(make_tuple(A[a] + B[b] + C[c+1], a, b, c+1)); used_idx.insert(to_use_idx(a, b, c+1));}
        
    }

    for (int i = 0; i < k; i++) cout << sum_list[i] << endl;
    return 0;
}
