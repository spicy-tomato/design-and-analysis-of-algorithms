/*
 * http://laptrinhonline.club/problem/tichpxsapxepbalo
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, v, q, m;
    cin >> n;

    vector<vector<int>> knapsack = vector<vector<int>>(n, vector<int>(1e4, 0));

    for (int i = 0; i < n; ++i)
    {
        cin >> s >> v;
        for (int w = 0; w <= 1e4; ++w)
        {
            if (w == 0)
                knapsack[i][w] = 0;
            else if (i == 0)
            {
                if (w < s)
                    knapsack[0][w] = 0;
                else
                    knapsack[0][w] = v;
            }
            else if (s <= w)
                knapsack[i][w] = max(
                        v + knapsack[i - 1][w - s],
                        knapsack[i - 1][w]
                );
            else
                knapsack[i][w] = knapsack[i - 1][w];
        }
    }

    cin >> q;
    while (q--)
    {
        cin >> m;
        if (m <= 0)
            cout << 0;
        else if (m <= 1e4)
            cout << knapsack[n - 1][m];
        else
            cout << knapsack[n - 1][1e4];
        cout << '\n';
    }
}
