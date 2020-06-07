#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>  
#define ll long long
  
using namespace std; 

int N,M,L;

ll inf = 99999999999999;

int main() {
    cin >> N >> M >> L;
    ll dist[N][N]; // Oil refill, left (-1 is impossible)
    ll dist_oil[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if (L >= C) {
            dist[A-1][B-1] = C;
            dist[B-1][A-1] = C;
        }
    }

    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    // Floyd!!!
    for (int k = 0; k < N; k ++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                if ((dist[i][k] != -1) & (dist[k][j] != -1)) {

                    if (((dist[i][k] + dist[k][j]) < dist[i][j]) | (dist[i][j] == -1)) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }    
                }    
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            dist_oil[i][j] = (dist[i][j] > L) | (dist[i][j] == -1) ? -1 : 1;
        }
    }

    for (int k = 0; k < N; k ++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                if ((dist_oil[i][k] != -1) & (dist_oil[k][j] != -1)) {

                    if (((dist_oil[i][k] + dist_oil[k][j]) < dist_oil[i][j]) | (dist_oil[i][j] == -1)) {
                        dist_oil[i][j] = dist_oil[i][k] + dist_oil[k][j];
                    }    
                }    
            }
        }
    }

    int Q;
    cin >> Q;
    int answers[Q];
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        answers[i] = dist_oil[u-1][v-1];
    }

    for (int i = 0; i < Q; i++) {
        if (answers[i] == -1) cout << answers[i] << endl;
        else cout << answers[i] - 1 << endl;
    }

}