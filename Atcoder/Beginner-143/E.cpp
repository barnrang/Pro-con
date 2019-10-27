#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>  
#define ll long long
  
using namespace std; 

int N,M,L;

int main() {
    cin >> N >> M >> L;
    pair<ll, ll> dist[N][N]; // Oil refill, left (-1 is impossible)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = make_pair(-1, -1);
        }
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if (L >= C) {
            dist[A-1][B-1] = make_pair(0, L-C);
            dist[B-1][A-1] = make_pair(0, L-C);
        }
    }

    for (int i = 0; i < N; i++) {
        dist[i][i] = make_pair(0, L);
    }

    // Floyd!!!
    for (int k = 0; k < N; k ++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                // Check if route exist
                if ((dist[i][k].first != -1) && (dist[k][j].first != -1)) {
                    ll min_refill, left_oil;
                    left_oil = dist[i][k].second + dist[k][j].second - L;
                    
                    // Calculate minimum refill from i->k->j and its left oil
                    if (left_oil >= 0) {
                        // If oil is enough without refill at city k
                        // cout << i << " " << j << " "  << k << endl;
                        min_refill = dist[i][k].first + dist[k][j].first;
                    } else {
                        // Need to fill the tank at city k
                        cout << "Enter fill:" << i+1 << " " << j+1 << " "  << k+1 << " " << dist[i][k].first 
                            << " " << dist[k][j].second << endl;
                        left_oil = dist[k][j].second;
                        min_refill = dist[i][k].first + dist[k][j].first + 1;
                    }

                    // Apply if better than the existed

                    if ((dist[i][j].first == -1) || (min_refill < dist[i][j].first)
                        || ((dist[i][j].first == min_refill) & (left_oil > dist[i][j].second))) {
                            cout << "Renew:" << i+1 << " " << j+1 << " "  << k+1 << " " << min_refill << " " << left_oil << endl;
                            dist[i][j] = make_pair(min_refill, left_oil);
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
        answers[i] = dist[u-1][v-1].first;
    }

    for (int i = 0; i < Q; i++) {
        cout << answers[i] << endl;
    }

}