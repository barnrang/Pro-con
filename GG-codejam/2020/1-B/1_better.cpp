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
    string output = "";
    ll x, y;
    cin >> x >> y;
    
    ll abs_x = abs(x);
    ll abs_y = abs(y);
    

    if ((x+y) % 2 == 0) {
        cout << "Case #" << no << ": " << "IMPOSSIBLE" << endl;
        return; 
    }

    while ((abs_x + abs_y) != 1) {
        if (abs_x % 2 == 1) {
            if ((abs_x + abs_y - 1) % 4 != 0) {
                if (x > 0) {
                    output += "E";
                } 
                else {
                    output += "W";
                }
                abs_x = (abs_x - 1) / 2;
                abs_y = abs_y / 2;

            }
            else {
                if (x > 0) {
                    output += "W";
                } 
                else {
                    output += "E";
                }
                abs_x = (abs_x + 1) / 2;
                abs_y = abs_y / 2;
            }
        }

        else if (abs_y % 2 == 1) {
            if ((abs_x + abs_y - 1) % 4 != 0) {
                if (y > 0) {
                    output += "N";
                } 
                else {
                    output += "S";
                }
                abs_x = abs_x / 2;
                abs_y = (abs_y - 1) / 2;
            }
            else {
                if (y > 0) {
                    output += "S";
                } 
                else {
                    output += "N";
                }
                abs_x = abs_x / 2;
                abs_y = (abs_y + 1) / 2;
            }
        }
    }

    if (abs_x == 1) {
        if (x > 0) {
            output += "E";
        } 
        else {
            output += "W";
        }
    }

    if (abs_y == 1) {
        if (y > 0) {
            output += "N";
        } 
        else {
            output += "S";
        }
    }

    cout << "Case #" << no << ": " << output << endl;

}