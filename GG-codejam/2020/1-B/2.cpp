#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#define ll long long
using namespace std;

const ll BLOCK = 1e9 / 2;
const ll LEFT_MOST = -1e9, BOTTOM_MOST = -1e9, RIGHT_MOST = 1e9, TOP_MOST = 1e9; 
ll a, b;

void do_case(int i);

int main() {
    int n;
    cin >> n >> a >> b;
    for(int i = 1; i < n+1; i++){
        do_case(i);
    }
    return 0;
}

ll binary_pos_search_x(ll st, ll ed, int y) {

    if (abs(st - ed) <= 1) return st;

    string response;
    ll mid = (st + ed) / 2;
    cout << mid << " " << y << endl;
    cin >> response;
    cerr << response << endl;
    if (response == "HIT") {
        return binary_pos_search_x(mid, ed, y);
    }
    else if (response == "MISS") {
        return binary_pos_search_x(st, mid, y);
    }
    else if (response == "CENTER") {
        return 0;
    }
    else if (response == "WRONG") {
        exit(1);
    }
}

ll binary_pos_search_y(ll st, ll ed, int x) {

    if (abs(st - ed) <= 1) return st;

    string response;
    ll mid = (st + ed) / 2;
    cout << x << " " << mid << endl;
    cin >> response;
    cerr << response << endl;
    if (response == "HIT") {
        return binary_pos_search_y(mid, ed, x);
    }
    else if (response == "MISS") {
        return binary_pos_search_y(st, mid, x);
    }
    else if (response == "CENTER") {
        return 0;
    }
    else if (response == "WRONG") {
        exit(1);
    }

}

void do_case(int i) {

    string response;



    ll x,y;
    bool hit = false;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++){
            x = BLOCK * i + LEFT_MOST;
            y = BLOCK * j + BOTTOM_MOST;
            cout << x << " " << y << endl;
            cin >> response;
            if (response == "HIT") {
                hit = true;
                break;
            }
            if (response == "CENTER") {
                return;
            }
            else if (response == "WRONG") {
                exit(1);
            }
        }
        if (hit) break;   
    }
    ll x_left = binary_pos_search_x(x, LEFT_MOST, y);
    ll x_right = binary_pos_search_x(x, RIGHT_MOST, y);
    ll x_center = (x_left + x_right) / 2;

    ll y_top = binary_pos_search_y(y, TOP_MOST, x);
    ll y_bottom = binary_pos_search_y(y, BOTTOM_MOST, x);
    ll y_center = (y_bottom + y_top) / 2;

    cout << x_center << " " << y_center << endl;
    cin >> response; 
    if (response != "CENTER") {
        for (int i = -3; i <= 3; i++) {
            for (int j = -3; j <= 3; j++) {
                cout << x_center + i << " " << y_center + j << endl;
                cin >> response;
                if (response == "CENTER") return;
            }
        }
    }

    return;

}