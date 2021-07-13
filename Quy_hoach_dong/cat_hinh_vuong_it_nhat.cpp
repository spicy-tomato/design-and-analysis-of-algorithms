/*
 * http://laptrinhonline.club/problem/tichpxcathinhvuong
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int width, height;
    cin >> width >> height;

    if (width < height)
    {
        int tmp = width;
        width = height;
        height = tmp;
    }

    vector<vector<int>> dp = vector<vector<int>>(height + 1, vector<int>(width + 1, INT_MAX));

    for (int h = 1; h <= height; h++)
    {
        for (int w = 1; w <= width; ++w)
        {
            if (h == 1)
                dp[1][w] = w;
            else if (h == w)
                dp[h][w] = 1;
            else if (h > w)
                dp[h][w] = dp[w][h];
            else
            {
                for (int i = 1; i * 2 <= w; i++)
                    dp[h][w] = min(dp[h][w], dp[h][i] + dp[h][w - i]);
                for (int i = 1; i * 2 <= h; i++)
                    dp[h][w] = min(dp[h][w], dp[i][w] + dp[h - i][w]);
            }
        }
    }

    cout << dp[height][width];
}
