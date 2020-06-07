#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>  
#define ll long long
  
using namespace std; 

int main(){
    int n,m;
    cin >> n >> m;
    int pointer[200000];

    for (int i = 0; i < 200000; i++) pointer[i] = -1;
    pointer[0] = 0;

    vector< vector<int>> adj;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        adj.push_back(tmp);
    }

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    queue<int> check_nodes;
    check_nodes.push(0);
    while(!check_nodes.empty()) {
        int cn = check_nodes.front();
        check_nodes.pop();
        for (int ad : adj[cn]) {
            if (pointer[ad] == -1) {
                pointer[ad] = cn;
                check_nodes.push(ad);
            }
        }
    }

    bool found = true;
    for (int i = 0; i < n; i++) {
        if (pointer[i] == -1){ 
            found = false;
            break;    
        }
    }

    if (found) {
        cout << "Yes" << endl;
        for (int i = 1; i < n; i++) {
            cout << pointer[i]+1 << endl;
        }
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}