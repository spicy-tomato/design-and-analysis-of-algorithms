/*
 * http://laptrinhonline.club/problem/tichpxfloyd
 */

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, m, q;
    int f, t, w;

    cin >> n >> m >> q;
    vector<vector<int>> matrix = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX));

    while (m--)
    {
        cin >> f >> t >> w;
        matrix[f][t] = w;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int from = 1; from <= n; ++from)
        {
            if (from == k) continue;
            for (int to = 1; to <= n; ++to)
            {
                if (to == k) continue;
                long long shortestPath = min(
                        (long long) matrix[from][to],
                        (long long) matrix[from][k] + (long long) matrix[k][to]);

                matrix[from][to] = shortestPath > INT_MAX ? INT_MAX : int(shortestPath);
            }
        }
    }

    while (q--)
    {
        cin >> f >> t;
        cout << (matrix[f][t] == INT_MAX ? -1 : matrix[f][t]) << '\n';
    }
}
