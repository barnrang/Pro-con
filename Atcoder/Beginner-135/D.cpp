#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll R_list[100000][10];
int MOD = 1000000007;

void print_array(ll* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {

    string S;
    // vector<int> Q_digit;

    // Initial Setup
    int digit_val = 1;
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 10; j++) {
            R_list[i][j] = (j * digit_val) % 13;
        }
        digit_val = (digit_val * 10) % 13;
    }

    getline(cin, S);
    reverse(S.begin(), S.end());

    // cout << S << endl;

    int r_sum = 0;
    ll count_r1[13];
    ll count_r2[13];
    for (int i = 0; i < 13; i++) {
        count_r1[i] = 0;
        count_r2[i] = 0;    
    }

    count_r1[0] = 1;

    bool entered = false;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '?'){
            if (!entered) {
                for (int j = 0; j < 10; j++) {
                    count_r1[R_list[i][j]] = 1;
                }
            }
            else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++){
                        count_r2[((R_list[i][j] + k + 13) % 13)] += count_r1[k];
                    }
                    // print_array(count_r2, 13);
                }
                for (int k = 0; k < 13; k++){
                    count_r1[k] = count_r2[k] % MOD;
                    count_r2[k] = 0;
                }
            }
            // print_array(count_r1, 13);
            // print_array(R_list[i], 10);
            entered = true;
        }  
        else {
            r_sum += R_list[i][(int)(S[i] - '0')];
            // cout << R_list[i][(int)(S[i] - '0')] << endl;
        }
    }

    r_sum %= 13;
    // cout << r_sum << endl;
    cout << count_r1[(18 - r_sum) % 13]  << endl;

    return 0;
}