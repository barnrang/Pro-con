#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>  
#define ll long long
  
using namespace std; 

int main() {
    int N;
    cin >> N;
    int A[N];
    int C[N];
    int D[N+1];
    int F[N+1];
    int out[N+1];
    ll acc_sum1[N+1], acc_sum2[N+1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[i] = 0;
        D[i] = 0;
        acc_sum1[i] = 0;
        acc_sum2[i] = 0;
        out[i] = 0;
    }

    acc_sum1[N] = acc_sum2[N] = 0;
    D[N] = 0;
    out[N] = 0;

    for (int i = 0; i < N; i++) {
        C[A[i] - 1]++;
    }

    for (int i = 0; i < N; i++) {
        D[C[i]]++;
    }

    // Accumulate sum
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += i * D[i];
        sum2 += D[N - i];
        acc_sum1[i + 1] = sum1;
        acc_sum2[N - i - 1] = sum2;
    }

    for (int i = 1; i < N+1; i++) {
        F[i] = (acc_sum1[i] + acc_sum2[i]) / i;
    }

    int pointer = 1;
    for (int i = N; i >= 1; i--) {
        int max_lenght = F[i];
        int max_num = i;
        pointer = max_lenght;
        while (F[i] == max_lenght) {
            out[pointer] = max_num;
            i--;
            pointer++;
            if (i < 1) break;
        }
    }

    for (int i = 1; i < N+1; i++) {
        cout << out[i] << endl;
    }

}