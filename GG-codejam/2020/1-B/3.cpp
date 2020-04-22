#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

void do_case(int i);

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n+1; i++){
        do_case(i);
    }
    return 0;
}

int get_sum(int* arr, int st, int ed) {
    int acc = 0;
    for (int i = st; i < ed; i++) {
        acc += arr[i];
    }

    return acc;
}

int mod(int n, int p){
    return (n + abs(n) * p) % p;
}

void do_case(int no) {
    int r, s;
    cin >> r >> s;
    int t = (r * (s-1) + 1)/2;
    cout << "Case #" << no << ": " << t << endl;
    
    int count_list[100];

    for (int i = 0; i < r; i++) {
        count_list[i] = 1;
    }


    int idx = r - 1;

    for (int i = 0; i < t-1; i++) {
        int a = get_sum(count_list, 0, 2);
        int b = get_sum(count_list, 2, r) + 1;
        cout << a << " " << b << endl;

        count_list[mod(idx, r)]++; count_list[mod(idx-1, r)]++;
        idx -= 2; 
    }

    if (r * (s-1) % 2 == 1) {
        int a = count_list[0];
        int b = get_sum(count_list, 1, r);
        cout << a << " " << b << endl;
    }
    else {
        int a = get_sum(count_list, 0, 2);
        int b = get_sum(count_list, 2, r) + 1;
        cout << a << " " << b << endl;
    }
    return;
}