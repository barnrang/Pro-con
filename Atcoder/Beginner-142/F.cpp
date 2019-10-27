#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>  
#define ll long long
  
using namespace std; 

vector<int> graph[1000]; 

void print_array(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void print_vector(vector<int> A) {
    for (auto x : A) {
        cout << x << ' ';
    }
    cout << endl;
}

void find_loop(int st_node, int N, vector<int> &coll) {
    int from_node[N], visited[N];
    queue<int> next_node;
    for (int i = 0; i < N; ++i) visited[i] = 0;
    next_node.push(st_node);
    visited[st_node] = 1;

    while (!next_node.empty()) {
        bool loop = false;
        int curr_node = next_node.front();
        next_node.pop();
        for (auto vx : graph[curr_node]) {
            if (!visited[vx]) {
                next_node.push(vx);
                from_node[vx] = curr_node;
                visited[vx] = 1;
            }
            if (vx == st_node) {
                // Loooop
                loop = true;
                from_node[vx] = curr_node;
                break;
            }
        }
        if (loop) {
            // Collect loop nodes
            int pointer = st_node;
            do
            {
                coll.push_back(pointer);
                pointer = from_node[pointer];
            } while (pointer != st_node);
            break;
        }
    }
    // print_array(from_node, N);
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
    }

    vector<int> collect;
    for (int i = 0; i < N; i++) {
        find_loop(i, N, collect);
        if (collect.size() > 0) {
            cout << collect.size() << endl;
            for (auto x : collect) {
                cout << x+1 << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}