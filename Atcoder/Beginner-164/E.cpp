#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

struct edge
{
    ll des;
    ll m;
    ll t;
};


vector<edge> adj[50];

ll dp1[50][2501], dp2[50][2501];

int main() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 2501; j++) {
            dp1[i][j] = 9e12;
            dp2[i][j] = 9e12;
        }
    }

    ll n,m,s;
    cin >> n >> m >> s;

    ll sm = 0;
    for (int i = 0; i < m; i++) {
        ll u,v,a,b;
        cin >> u >> v >> a >> b;
        edge tmp1, tmp2;
        tmp1.des = v-1; tmp2.des = u-1;
        tmp1.m = tmp2.m = -a;
        sm += a;
        tmp1.t = tmp2.t = b;
        adj[u-1].push_back(tmp1);
        adj[v-1].push_back(tmp2);
    }

    sm = (float)(sm / m) * 50;
    sm = 2500;

    if (s >= sm) s = sm-1;
    dp1[0][s] = 0;

    for (int i = 0; i < n; i++) {
        ll c,d;
        cin >> c >> d;
        edge tmp = {i, c, d};
        adj[i].push_back(tmp);
    }

    // cout << "test" << endl;
    for (int i = 0; i < 2550; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < sm; k++) {
                for (auto &x : adj[j]) {
                    if (i % 2 == 0){
                        ll n_m = k + x.m;
                        if (n_m >= sm) n_m = sm-1;
                        ll n_tim = dp1[j][k] + x.t;
                        if (n_m < 0) continue;
                        if (n_tim < dp2[x.des][n_m]) {
                            dp2[x.des][n_m] = n_tim;
                        }
                    }
                    if (i % 2 != 0){
                        ll n_m = k + x.m;
                        if (n_m >= sm) n_m = sm-1;
                        ll n_tim = dp2[j][k] + x.t;
                        if (n_m < 0) continue;
                        if (n_tim < dp1[x.des][n_m]) {
                            dp1[x.des][n_m] = n_tim;
                        }
                    }
                    
                }   
            }
        }
    }

    for (int i = 1; i < n; i++){
        ll mn = 1e12;
        for (int j = 0; j < sm; j++) {
            if (mn > dp1[i][j]) {
                mn = dp1[i][j];
            }

        }
        cout << mn << endl;
    }

    return 0;

}