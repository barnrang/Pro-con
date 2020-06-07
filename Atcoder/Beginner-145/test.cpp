#include <bits/stdc++.h>

int main() {
    float x = 1000000000;

    for(int i = 0; i < 1e9; i++) {
        x += 1e-9;
    }

    std::cout << x;
}