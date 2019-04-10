#include <iostream>
using namespace std;
#define ll long long
#define to_mod 1000000007

int main(){
    int n;
    cin >> n;
    char a_int = 'a';
    ll alphs[26];
    for(int i = 0; i < 26; i++) alphs[i] = 1;
    for(int i = 0; i < n; i++){
        char inp;
        cin >> inp;
        // cout << int(inp) - int(a_int) << endl;
        alphs[int(inp) - int(a_int)]++;
    }
    ll comb = 1;
    for(int i = 0; i < 26; i++) {comb *= alphs[i]; comb = (comb + to_mod) % to_mod;}
    cout << comb - 1 << endl;
    return 0;
}