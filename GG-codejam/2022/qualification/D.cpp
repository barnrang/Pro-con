// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

vv32 graph;
v64 funs;
v32 abyss;

ll overall_sum=0;

ll recur(int index) {
    // cout << "Enter recur " << index << " of value " << funs[index] << endl;
    v32 prev_nodes = graph[index];
    if (prev_nodes.size() == 1) {
        ll max_fun = 0;
        max_fun = max(max_fun, funs[index]);
        while(prev_nodes.size() == 1){
            max_fun = max(max_fun, funs[prev_nodes[0]]);
            prev_nodes = graph[prev_nodes[0]];
        }    

        if (prev_nodes.size() == 0) {
            return max_fun;
        }
        else {

            ll mini = 99999999999999;
            ll sm_prev = 0;
            for(int node: prev_nodes) {
                // priority_queue<ll, vector<ll>, greater<ll> > another_fun_heap;
                ll from_prev = recur(node);
                sm_prev += from_prev;
                mini = min(mini, from_prev);
            }

            overall_sum += sm_prev - mini;

            if (mini >= max_fun) {
                return mini;
            }
            else {
                return max_fun;
            }

        }
    }
    else if (prev_nodes.size() == 0) {
        return funs[index];
    }
    else {
        ll mini = 99999999999999;
        ll sm_prev = 0;
        for(int node: prev_nodes) {
            // priority_queue<ll, vector<ll>, greater<ll> > another_fun_heap;
            ll from_prev = recur(node);
            sm_prev += from_prev;
            mini = min(mini, from_prev);
        }

        overall_sum += sm_prev - mini;

        if (mini >= funs[index]) {
            return mini;
        }
        else {
            return funs[index];
        }
    }
} 

void solve(int i) {
    int n;
    graph.clear();
    funs.clear();
    abyss.clear();
    overall_sum = 0;
    cin >> n;
    forn(i, n) {
        v32 tmp;
        graph.push_back(tmp);
    }

    forn(i, n) {
        ll tmp;
        cin >> tmp;
        funs.push_back(tmp);
    }

    forn(i, n) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            abyss.push_back(i);
        }
        else {
            graph[tmp-1].push_back(i);
        }
    }

    for (int i : abyss) {
        ll last = recur(i);

        overall_sum += last;

        
    }

    cout << "Case #" << i << ": " <<  overall_sum << endl;
}

int main() {
    int T = 0;
    cin >> T;
    forn(i, T) {
        solve(i+1);
    }
    return 0;
}