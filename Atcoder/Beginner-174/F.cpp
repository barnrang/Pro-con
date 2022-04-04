#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 500001
#define node pair<int,int>

vector<int> yoi(MAX);
vector<int> tree(MAX);
vector<int> ans(MAX);
vector<node> save_idx;

vector<int> balls;
vector<node> intes;

ll N,Q;


void update_tree(int index, int value)
{
    while (index <= N)
    {
        tree[index] += value;
        index += index & (-index);
    }
}

int get_sum(int index)
{
    int s = 0;
    while (index > 0)
    {
        s+= tree[index];
        index -= index & (-index);
    }

    return s;
}

bool cmpfn(node a, node b){
    return a.second < b.second;
}

int main() 
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        balls.push_back(tmp);
    }

    for (int i = 0; i < Q; i++)
    {
        int l,r;
        cin >> l >> r;
        // index + 1
        intes.push_back(make_pair(l,r));
        save_idx.push_back(make_pair(i, r));
    }

    sort(intes.begin(), intes.end(), cmpfn);
    sort(save_idx.begin(), save_idx.end(), cmpfn);

    for (int i = 0; i < N+1; i++)
    {
        tree[i] = 0;
    }

    int prev_r = 0;
    int count = 0;
    for (auto inte: intes)
    {
        int cu_r = inte.second;
        if (cu_r > prev_r)
        {
            for (int i = prev_r+1; i <= cu_r; i++)
            {
                int c = balls[i-1];
                if (yoi[c] == 0)
                {
                    update_tree(i, 1);
                }
                else
                {
                    update_tree(yoi[c], -1);
                    update_tree(i, 1);
                }

                yoi[c] = i;
            }
        }

        int sum = get_sum(cu_r) - get_sum(inte.first - 1);

        ans[save_idx[count].first] = sum;
        // ans[count] = sum;
        prev_r = cu_r;
        count++;
    }

    for (int i = 0; i < Q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}