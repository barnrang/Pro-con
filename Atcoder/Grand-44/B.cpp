#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> node;

int tab[500][500];
bool sit[500][500];
vector<int> pp;

int n;

void print_tab() 
{
    for (int i = 0;i < n ;i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

node get_co(int k) {
    int i = k / n;
    int j = k % n;
    return make_pair(i,j);
}

vector<node> get_neigh(int x, int y)
{
    vector<node> tmp;
    if ((x-1) >= 0) tmp.push_back(make_pair(x-1, y));
    if ((x+1) < n) tmp.push_back(make_pair(x+1, y));
    if ((y-1) >= 0) tmp.push_back(make_pair(x, y-1));
    if ((y+1) < n) tmp.push_back(make_pair(x, y+1));

    return tmp;
}

int main() {
    
    cin >> n;
    for (int i = 0; i < (n * n); i++) {
        int tmp;
        cin >> tmp;
        pp.push_back(tmp-1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int min_w = min(i, abs(n-i-1));
            int min_h = min(j, abs(n-j-1));
            tab[i][j] = min(min_w, min_h);
            sit[i][j] = 1;
        }
    }


    ll hate = 0;
    for (int p : pp) {
        node tmp = get_co(p);
        int x = tmp.first;
        int y = tmp.second;

        hate += tab[x][y];
        sit[x][y] = 0;

        // Update Cost
        queue<node> to_update;
        to_update.push(make_pair(x,y));
        while (!to_update.empty()) 
        {
            node now = to_update.front();
            to_update.pop();
            int x_now = now.first;
            int y_now = now.second;

            vector<node> neighbor = get_neigh(x_now, y_now);

            int n_cost = sit[x_now][y_now] * 1 + tab[x_now][y_now];
            for (auto nb: neighbor)
            {
                int x_n = nb.first;
                int y_n = nb.second;
                if (tab[x_n][y_n] > n_cost)
                {
                    tab[x_n][y_n] = n_cost;
                    to_update.push(make_pair(x_n, y_n));
                }
            }
        }
    }

    cout << hate << endl;
    return 0;
}