#include <iostream>
using namespace std;

int main(){
    int d = 1000;
    bool* occupy = new bool[d * d * d];
    cout << d;
    
    for(int i = 0; i< d; i++){
        for(int j = 0; j< d; j++){
            for(int k = 0; k < d; k++){
                occupy[i * d * d + j * d + k] = false;
            }
        }
    }
    

    return 0;
}
