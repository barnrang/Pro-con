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
int main()
{
    int n;
    cin >> n;

    vp64 coor;
    forn(i, n) {
        ll x,y;
        cin >> x >> y;
        coor.push_back(make_pair(x, y));
    }

    // if (coor[i][0] - coor[j][0]) == 0 or (coor[i][0] - coor[k][0]) == 0 or (coor[j][0] - coor[k][0]) == 0:
    //             if (coor[i][0] - coor[j][0]) != 0 or (coor[i][0] - coor[k][0]) != 0 or (coor[j][0] - coor[k][0]) != 0 :
    //                 count += 1
    //             continue
    //         tana = (coor[i][1] - coor[j][1]) / (coor[i][0] - coor[j][0])
    //         tanb = (coor[i][1] - coor[k][1]) / (coor[i][0] - coor[k][0])
    //         tanc = (coor[j][1] - coor[k][1]) / (coor[j][0] - coor[k][0])
    //         if tana != tanb or tanb != tanc or tana != tanc:
    //             count += 1  

    ll count = 0;
    forn(i, n) {
        forsn(j, i+1, n) {
            forsn(k, j+1, n) {
                double dx1, dx2, dx3, dy1, dy2, dy3;
                dx1 = coor[i].first - coor[j].first;
                dx2 = coor[i].first - coor[k].first;
                dx3 = coor[j].first - coor[k].first;

                dy1 = coor[i].second - coor[j].second;
                dy2 = coor[i].second - coor[k].second;
                dy3 = coor[j].second - coor[k].second;

                if (dx1 == 0 || dx2 == 0 || dx3 == 0) {
                    if (dx1 != 0 || dx2 != 0 || dx3 != 0) {
                        count++;
                    }
                    continue;
                }

                double tana, tanb, tanc;
                tana = dy1 / dx1;
                tanb = dy2 / dx2;
                tanc = dy3 / dx3;

                if (tana != tanb || tanb != tanc || tana != tanc) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}