#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
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
 

void solve(){
}
int get_empty_index(v32& states) {
    forn(i, states.size()) {
        if (states[i] == -1) return i;
    }
}

void copy_vector(v32& s1, v32& s2) {
    for (int x : s1) {
        s2.push_back(x);
    }
}

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

bool check_same(v32& s1, v32& s2) {
    forn(i, s1.size()) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

int main()
{
    int m;
    cin >> m;
    vv32 edges(9);
    forn(i, m) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    unordered_map<v32, ll, VectorHasher> min_move;
    v32 state(9, -1);
    v32 final_state(9, -1);
    forn(i, 8) {
        int p ;
        cin >> p;
        state[p-1] = i;
        final_state[i] = i;
    }

    if (check_same(state, final_state))  {
        cout << 0 << endl;
        return 0;
    }

    queue<v32> states;
    min_move[state] = 0;
    states.push(state);

    while(!states.empty()){
        v32 current_state = states.front();
        states.pop();
        int idx = get_empty_index(current_state);

        for (int adj : edges[idx]) {
            v32 new_state;
            copy_vector(current_state, new_state);
            new_state[idx] = new_state[adj];
            new_state[adj] = -1;
            if (min_move.find(new_state) == min_move.end()) {
                if (check_same(new_state, final_state))  {
                    cout << min_move[current_state] + 1 << endl;
                    return 0;
                }
                min_move[new_state] = min_move[current_state] + 1;
                states.push(new_state);
            }
        }
    }

    cout << -1 << endl;
    return 0;

}