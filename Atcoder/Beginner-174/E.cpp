#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N,K;
vector<ll> logs;
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) 
    {
        ll tmp;
        cin >> tmp;
        // cout << tmp;
        logs.push_back(tmp);
    }

    ll lo = 1;
    ll hi = 1000000000;
    ll mid;
    while (1)
    {
        if (hi <= lo) {
            mid = lo;
            break;
        }
        mid = (hi + lo) / 2;
        // cout << hi << " " << lo << " " << mid << endl;
        ll cut = 0;
        for (auto& len : logs)
        {
            cut += ceil((double)len / (double)mid) - 1;
        }

        // cout << hi << " " << lo << " " << mid << " " << cut << endl;

        if (cut <= K)
        {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << mid << endl;
    return 0;

}