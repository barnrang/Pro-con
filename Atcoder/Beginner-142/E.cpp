#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>  
#define ll long long

int states = 4096;
int N_MAX = 12;
  
using namespace std; 

int convert_to_state(int* bit_map) {
    int multi = 1;
    int sum = 0;
    for (int i = 0; i < N_MAX; i++) {
        sum += multi * bit_map[i];
        multi *= 2;
    }
    return sum;
}

void set_zero(int* bit_map) {
    for (int i = 0; i < N_MAX; i++) {
        bit_map[i] = 0;
    } 
}

void print_array(ll* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void print_array(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

int main() {
    int bit_map[N_MAX];
    ll cost[states];
    ll tmp_cost[states];
    for (int i = 0; i < states; i++) {
        cost[i] = -1;
    }
    cost[0] = 0;

    for (int i = 0; i < N_MAX; i++) {
        bit_map[i] = 0;
    } 

    int N, M;
    cin >> N >> M;
    int states_arr[M], moneys[M];
    // cout << &states_arr[1] << endl;
    for (int i = 0; i < M; i++) {
        int a, b, idx;
        cin >> a >> b;
        set_zero(bit_map);
        for (int j = 0; j < b; j++) {
            cin >> idx;
            bit_map[idx-1] = 1;
        }
        states_arr[i] = convert_to_state(bit_map);
        // print_array(states_arr, M);
        moneys[i] = a;
        // print_array(states_arr, M);
    }

    // print_array(moneys, M);


    int merge_state;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < states; j++) {
            tmp_cost[j] = cost[j];
        }
        for (int j = 0; j < states; j++) {
            if (cost[j] == -1) continue;
            merge_state = states_arr[i] | j;
            if (tmp_cost[merge_state] == -1) {
                tmp_cost[merge_state] = cost[j] + moneys[i];
            }
            else {
                tmp_cost[merge_state] = tmp_cost[merge_state] > (cost[j] + moneys[i]) ? 
                     (cost[j] + moneys[i]) : tmp_cost[merge_state];
            }
        }
        for (int j = 0; j < states; j++) {
            cost[j] = tmp_cost[j];
        }
        // print_array(cost, 4);
    }

    int target = 1;
    for (int i = 0; i < N; i++) target *= 2;
    target--;

    // print_array(cost, 4);
    cout << cost[target] << endl;

}