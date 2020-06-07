#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX=1e18;
ll a,b,c,d;


map<ll, ll> mem;
ll solve(ll n)
{
    if (mem.count(n)) return mem[n];
    if (n == 1) return d;
    if (n == 0) return 0;

    ll ans;
    if (n < MAX/d) ans = n * d;
    else ans=MAX;

    ll l2 = (n/2);
    ll r2 = (n+1) / 2;
    ll l3 = (n/3);
    ll r3 = (n+2) / 3;
    ll l5 = (n/5);
    ll r5 = (n+4) / 5;

    ans = min(ans, llabs(l2 * 2 - n) * d + a + solve(l2));
    ans = min(ans, llabs(r2 * 2 - n) * d + a + solve(r2));

    ans = min(ans, llabs(l3 * 3 - n) * d + b + solve(l3));
    ans = min(ans, llabs(r3 * 3 - n) * d + b + solve(r3));

    ans = min(ans, llabs(l5 * 5 - n) * d + c + solve(l5));
    ans = min(ans, llabs(r5 * 5 - n) * d + c + solve(r5));

    mem[n] = ans;

    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i=0;i<t;i++) {
        mem.clear();
        ll n;
        cin >> n >> a >> b >> c >> d;
        ll ans = solve(n);
        cout << ans << endl;
    }
    return 0;
}