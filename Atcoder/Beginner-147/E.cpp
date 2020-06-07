#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>  
#define ll long long
  
using namespace std; 

int MAX = 12801;

int offset(int x){
    return x + 6400;
}

int main() {
    int H,W;
    cin >> H >> W;
    vector<int> init(W, 0);
    
    vector< vector<int>> As(H, init);
    vector< vector<int>> Bs(H, init);

    vector<bool> init_diff(MAX, 0);
    vector< vector<bool>> init_diff2(W, init_diff);
    vector< vector< vector<bool>>> exist_diff(H, init_diff2);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> As[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> Bs[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

        }
    }



}