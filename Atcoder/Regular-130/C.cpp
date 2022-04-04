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
 
unordered_map<int, ll> a_dict, b_dict;


p32 find_match(int num){
    forsn(i, 1, min(10, num)) {
        if (a_dict[i] != 0 && b_dict[num-i] != 0) {
            return mp(i, num-i);
        }
    }

    return mp(-1,-1);
}

p32 determine_first_ten() {
    unordered_map<int, int> add_nine;
    forsn(i, 1, 9) {
        if (a_dict[i] != 0 && b_dict[9-i] != 0) {
            add_nine[i] = 1;
            add_nine[9-i] = 1;
        }
    }

    p32 best_pair;
    bool mark_best = false;
    bool found_match = false;

    forsn(i, 1, 10) {
        if (a_dict[i] != 0 && b_dict[10-i] != 0) {
            found_match = true;
            if (add_nine[i] == 0 && add_nine[10-i] == 0) {
                return mp(i, 10-i);
            }

            if (add_nine[i] == 0 && add_nine[10-i] != 0) {
                best_pair = mp(i, 10-i);
                mark_best = true;
            }

            if (add_nine[i] != 0 && add_nine[10-i] == 0) {
                best_pair = mp(i, 10-i);
                mark_best = true;
            }

            if (add_nine[i] != 0 && add_nine[10-i] != 0 && !mark_best) {
                best_pair = mp(i, 10-i);
            }
        }
    }

    if (found_match) return best_pair;
    else return mp(-1,-1);
}

int main()
{
    string a,b;
    cin >> a;
    cin >> b;

    v32 a_shuffle;
    v32 b_shuffle;

    int len_a = a.length();
    int len_b = b.length();

    ll min_loop = len_a > len_b ? len_b : len_a;
    forsn(i, 1, 10) {
        a_dict[i] = 0;
        b_dict[i] = 0;
    }
    forn(i, a.length()){
        a_dict[a[i] - '0'] += 1;
    }

    forn(i, b.length()){
        b_dict[b[i] - '0'] += 1;
    }

    bool tod = false;

    forn(i, min_loop) {
        int st;
        if (tod) {
            st = 9;
        } else {
            st = 10;
        }

        bool found_match = false;
        tod = false;

        p32 match_num;

        if (i == 0) {
            match_num = determine_first_ten();
            if (match_num.first != -1) {
                found_match = true;
                tod = true;
            }
            if (!found_match){
                forsn(j, st, 19) {
                    match_num = find_match(j);
                    if (match_num.first != -1) {
                        found_match = true;
                        tod = true;
                        break;
                    }
                }
            }
        } else {
            forsn(j, st, 19) {
                match_num = find_match(j);
                if (match_num.first != -1) {
                    found_match = true;
                    tod = true;
                    break;
                }
            }
        }

        if (found_match) {
            a_shuffle.push_back(match_num.first);
            b_shuffle.push_back(match_num.second);
            a_dict[match_num.first] -= 1;
            b_dict[match_num.second] -= 1;
        } else {
            break;
        }
    }

    rforsn(i,9,1) {
        while (a_dict[i] != 0){
            a_shuffle.push_back(i);
            a_dict[i] -= 1;
        }

        while (b_dict[i] != 0){
            b_shuffle.push_back(i);
            b_dict[i] -= 1;
        }
    }

    for (int i = a_shuffle.size() - 1; i >= 0 ; i--) {
        cout << a_shuffle[i];
    }

    cout << endl;

    for (int i = b_shuffle.size() - 1; i >= 0 ; i--) {
        cout << b_shuffle[i];
    }

    return 0;

}