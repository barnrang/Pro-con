#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
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

void print_array(int* a, int n) {
    cout << "[" << endl;
    for (int i = 0; i < n; i++){
        cout << a[i] << ", ";
    }

    cout << "]" << endl;
}

void do_case(int no) {
    ll x, y;
    cin >> x >> y;
    ll abs_sum = abs(x) + abs(y);
    if (abs_sum % 2 == 0) {
        cout << "Case #" << no << ": " << "IMPOSSIBLE" << endl;
        return;    
    }

    int max_digit = log2((double)abs_sum)+1;

    ll tmp = 1;
    for (int i = 0; i < max_digit; i++) {
        tmp = tmp * 2;
    }
    tmp--;
    ll diff_max = (tmp - abs_sum) / 2;
    string diff_bin = bitset<40>(diff_max).to_string();
    reverse(diff_bin.begin(), diff_bin.end());
    // cout << diff_bin << endl;
    int digit[40];
    for (int i = 0; i < 40; i++) digit[i] = 0;

    for (int i = 0; i < max_digit; i++) {
        if (diff_bin[i] == '0') {
            digit[i] = 1;
        }
        else if (diff_bin[i] == '1') {
            digit[i] = -1;
        } else {
            cout << "What the fuck" << endl;
        }
    }

    string x_bin = bitset<40>(abs(x)).to_string();
    reverse(x_bin.begin(), x_bin.end());

    string y_bin = bitset<40>(abs(y)).to_string();
    reverse(y_bin.begin(), y_bin.end());

    int x_digit[40];
    int y_digit[40];
    for (int i = 0; i < 40; i++) {
        x_digit[i] = 0;
        y_digit[i] = 0;
    }
    
    int pointer = 0;
    while (x_bin[pointer] != '1') pointer++;


    while (pointer < max_digit) {
        if (x_bin[pointer] == '1') {
            if (digit[pointer] == 1) {
                x_digit[pointer] = 1;
                pointer++;
                while (x_bin[pointer] == '0'){
                    pointer++;
                    if (pointer >= max_digit) break;
                }
            }
            else if (digit[pointer] == -1) 
            {
                x_digit[pointer] = -1; // Pass to next digit
                while (x_bin[pointer] == '1') {
                    pointer++;
                }
            }
        }

        else {
            if (digit[pointer] == 1) {
                // Case where values been pass right
                x_digit[pointer] = 1;
                while (x_bin[pointer] == '0') {
                    pointer++;
                }
            }

            else if (digit[pointer] == -1) {
                x_digit[pointer] = -1; // Pass to next digit
                pointer++; // See if next digit is 1
                while (x_bin[pointer] == '1') {
                    pointer++;
                }
            }
        }
    }

    for (int i = 0; i < max_digit; i++) {
        if (x_digit[i] == 0) {
            y_digit[i] = digit[i];
        }
    }

    if (x < 0) {
        for (int i = 0; i < max_digit; i++) {
            x_digit[i] *= -1;
        }
    }

    if (y < 0) {
        for (int i = 0; i < max_digit; i++) {
            y_digit[i] *= -1;
        }
    }

    string output = "";

    for (int i = 0; i < max_digit; i++) {
        if (x_digit[i] == 1) {
            output += "E";
        }
        if (x_digit[i] == -1) {
            output += "W";
        }
        if (y_digit[i] == 1) {
            output += "N";
        }
        if (y_digit[i] == -1) {
            output += "S";
        }
    }

    // print_array(x_digit, 10);
    // print_array(y_digit, 10);

    cout << "Case #" << no << ": " << output << endl;

}