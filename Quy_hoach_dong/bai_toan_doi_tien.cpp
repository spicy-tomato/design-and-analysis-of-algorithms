/*
 * http://laptrinhonline.club/problem/tichpxsudoku
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> denominations, cache, query;
int n, lastIndex = 0;

void solve()
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (i < denominations[0])
            cache[i] = 0;
        else
        {
            int minCount = INT_MAX;
            for (auto item : denominations)
            {
                if (i - item >= 0)
                {
                    if (cache[i - item] || i == item)
                        minCount = min(minCount, cache[i - item] + 1);
                }
                else
                    break;
            }

            if (minCount != INT_MAX)
                cache[i] = minCount;
        }
    }
}

int main()
{
    int q;

    cin >> n >> q;
    denominations = vector<int>(n);
    query = vector<int>(q);

    for (auto &i : denominations)
        cin >> i;

    for (auto &i : query)
    {
        cin >> i;
        lastIndex = max(i, lastIndex);
    }

    cache = vector<int>(lastIndex + 10, 0);

    sort(denominations.begin(), denominations.end());
    solve();

    for (auto& i : query){
        cout << (cache[i] ? cache[i] : -1) << '\n';
    }
}