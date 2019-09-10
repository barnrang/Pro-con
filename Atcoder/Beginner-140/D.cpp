#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    char begin_char = S[0];

    // Count initial happy
    int happy = 0;
    int swap = 0;
    bool final_swap = S[0] != S[N-1];
    if (S[0] == 'R' && S[1] == 'R') {
        happy++;
    }
    if (S[N-1] == 'L' && S[N-2] == 'L') {
        happy++;
    }
    for (int i = 1; i < N-1; i++) {
        if (S[i] == 'L' && S[i-1] == 'L') {
            happy++;
        }
        if (S[i] == 'R' && S[i+1] == 'R') {
            happy++;
        }
    }

    bool detect_diff = false;

    for (int i = 1; i < N ; i++) {
        if (!detect_diff && S[i] != begin_char) {
            detect_diff = true;
        } else if (detect_diff && S[i] == begin_char) {
            detect_diff = false;
            swap++;
        }
    }

    if (K >= swap) {
        K -= swap;
        happy += 2 * swap;
    } else {
        happy += 2*K;
        K = 0;
    }
    // Check if left over
    if (K > 0 && final_swap) {
        happy++;
    }
    cout << happy << "\n";

}