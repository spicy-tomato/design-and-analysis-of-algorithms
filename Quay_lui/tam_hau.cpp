/*
 * http://laptrinhonline.club/problem/tichpx8hau
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Save position of Queens
 * i       : i-nth row of board
 * board[i]: i-nth column of board
 */
vector<int> board;

int n, result;

bool columnConditionIsOk(int currentRow, int column)
{
    for (int row = 0; row < currentRow; ++row)
    {
        if (board[row] == column) return false;
    }

    return true;
}

bool diagonalConditionIsOk(int currentRow, int column)
{
    // Check from bottom-left to top-right
    int r = currentRow - 1, c = column + 1;
    while (r >= 0 && c < n)
    {
        if (board[r] == c) return false;
        r--;
        c++;
    }

    // Check from bottom-right to top-left
    r = currentRow - 1, c = column - 1;
    while (r >= 0 && c >= 0)
    {
        if (board[r] == c) return false;
        r--;
        c--;
    }

    return true;
}

void solve(int currentRow = 0)
{
    if (currentRow >= n)
    {
        result++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (col == currentRow)         continue; // On the main diagonal line
        if (col + currentRow == n - 1) continue; // On the anti diagonal

        if (currentRow == 0)
        {
            board[0] = col;
            solve(1);
        }
        else
        {
            if (columnConditionIsOk  (currentRow, col) &&
                diagonalConditionIsOk(currentRow, col))
            {
                board[currentRow] = col;
                solve(currentRow + 1);
            }
        }
    }
}

int main()
{
    cin >> n;
    board = vector<int>(n);

    solve();

    cout << result;
}