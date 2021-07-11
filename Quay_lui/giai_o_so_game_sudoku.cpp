/*
 * http://laptrinhonline.club/problem/tichpxsudoku
 */

#include <bits/stdc++.h>

using namespace std;

int matrix[81];
bool solved = false;

bool rowConditionIsOk(int currentIndex)
{
    int rowIndex = currentIndex / 9;
    unordered_map<int, bool> M;

    for (int col = 0; col < 9; ++col)
    {
        int index = rowIndex * 9 + col;
        if (matrix[index])
        {
            if (M[matrix[index]]) return false;
            M[matrix[index]] = true;
        }
    }

    return true;
}

bool columnConditionIsOk(int currentIndex)
{
    unordered_map<int, bool> M;
    int colIndex = currentIndex % 9;

    for (int row = 0; row < 9; ++row)
    {
        int index = row * 9 + colIndex;
        if (matrix[index])
        {
            if (M[matrix[index]]) return false;
            M[matrix[index]] = true;
        }
    }

    return true;
}

bool areaConditionIsOk(int currentIndex)
{
    unordered_map<int, bool> M;

    /*
     * | 0 | 1 | 2 |
     * | 3 | 4 | 5 |
     * | 6 | 7 | 8 |
     */

    int rowIndex = currentIndex / 9;
    int colIndex = currentIndex % 9;
    int firstCellIndex = (rowIndex / 3 * 27) + (colIndex / 3 * 3);

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int index = firstCellIndex + 9 * i + j;
            if (matrix[index])
            {
                if (M[matrix[index]]) return false;
                M[matrix[index]] = true;
            }
        }
    }

    return true;
}

void solve(int current = 0)
{
    if (current >= 81)
    {
        solved = true;
        return;
    }

    if (matrix[current])
    {
        solve(current + 1);
    }
    else
    {
        for (int i = 1; i <= 9 && !solved; ++i)
        {
            matrix[current] = i;
            if (rowConditionIsOk   (current) &&
                columnConditionIsOk(current) &&
                areaConditionIsOk  (current))
            {
                solve(current + 1);
            }
        }

        if (!solved)
            matrix[current] = 0;
    }
}

int main()
{
    for (auto &i : matrix)
        cin >> i;

    solve();

    for (int i = 0; i < 81; ++i)
    {
        cout << matrix[i] << ' ';
        if (i % 9 == 8) cout << '\n';
    }
}