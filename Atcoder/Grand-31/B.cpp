#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define to_mod 1000000007
#define MAX_COLOR 200001


int main(){
    int n;
    cin >> n;
    vector<int> each_color[MAX_COLOR];
    int num_each_color[MAX_COLOR];
    int color_coll[n];
    int idx_each_color[n];
    ll comb_points[n];
    comb_points[0] = 1;
    for(int i = 0; i < MAX_COLOR; i++) num_each_color[i] = 0;
    for(int i = 0; i < n; i++){
        int inp_color;
        cin >> inp_color;
        color_coll[i] = inp_color;
        idx_each_color[i] = num_each_color[inp_color];
        num_each_color[inp_color]++;
        each_color[inp_color].push_back(i);
    }
    for(int i = 1; i < n; i++) {
        int lst_color = color_coll[i];
        int idx_in_color = idx_each_color[i];
        if (idx_in_color == 0) comb_points[i] = comb_points[i-1];
        else {
            int prev_idx_in_color = each_color[lst_color][idx_in_color - 1];
            int diff = each_color[lst_color][idx_in_color] - prev_idx_in_color;
            if (diff > 1) comb_points[i] = comb_points[prev_idx_in_color] + 
                comb_points[i-1];
            else comb_points[i] = comb_points[i-1];
        }
        comb_points[i] = (comb_points[i] + to_mod) % to_mod;
    }

    cout << comb_points[n-1] << endl;
    return 0;
}