#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>  
#define ll long long
  
using namespace std; 
#define MAX 10000000

vector<ll> dp;
vector<ll> tables;
vector<ll> ways;
vector<bool> prm;


int main(){
    ll n;
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        tables.push_back(i);
        prm.push_back(true);
        ways.push_back(1);
    }


    for (int i = 1; i < n; i++)
    {
        ll c_num = tables[i];
        if (prm[i])
        {
            vector<ll> tmp;
            for (int j = i; j < n; j += c_num)
            {
                ll in_num = tables[j];
                prm[j] = false;
                int count = 1;
                in_num /= c_num;
                if (in_num % c_num == 0)
                {
                    ways[j] *= (tmp[in_num / c_num - 1] + 1);
                    tmp.push_back(tmp[in_num / c_num - 1] + 1);
                }
                else
                {
                    ways[j] <<= 1;
                    tmp.push_back(2);
                }
                

                // ways[j] *= count;

            }
        }
    }

    ll summ = 0;
    for (int i = 0; i < n; i++)
    {
        summ += (i+1) * ways[i];
        // cout << ways[i] << endl;
    }

    cout << summ << endl;


    dp.push_back(0);



    // ll s = 1;
    // dp.push_back(1);
    // for (int i = 2;i < n+1;i++)
    // {
    //     ll c_num = i;
    //     float sq = sqrt(i);
    //     ll f_prime = 1;
    //     for (auto j : primes)
    //     {
    //         if (j > sq) break;
    //         if (i % j == 0)
    //         {
    //             while(c_num % j == 0)
    //             {
    //                 f_prime += 1;
    //                 c_num /= j;
    //             }

    //             dp.push_back(dp[c_num] * f_prime);
    //             break;
    //         }
    //     }

    //     if (f_prime == 1)
    //     {
    //         s += i * 2;
    //         dp.push_back(2);
    //         primes.push_back(i);
    //     }
    //     else 
    //     {
    //         s += i * dp[i];
    //     }

    // }

    // cout << s << endl;
    return 0;
}