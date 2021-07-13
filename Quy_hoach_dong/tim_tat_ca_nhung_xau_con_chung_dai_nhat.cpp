/*
 * http://laptrinhonline.club/problem/tichpxxccdn
 */

#include <bits/stdc++.h>

using namespace std;

queue<pair<pair<int, int>, string>> visitQueue;
map<string, bool> result;
vector<vector<int>> cache;
string str1, str2;

void pushFirstTime()
{
    int row = str1.size() - 1, col = str2.size() - 1;

    int currentValue = cache[row][col], r1 = row, c1 = col;

    while (cache[r1][c1 - 1] == currentValue)
        c1--;
    if (c1 != col)
    {
        while (cache[r1 - 1][c1] == currentValue && r1 > 0)
            r1--;
    }
    if (r1 == 0) return;

    int r2 = row;
    int c2 = col;

    while (cache[r2 - 1][c2] == currentValue)
        r2--;
    if (r2 != row)
    {
        while (cache[r2][c2 - 1] == currentValue)
            c2--;
    }

    if (r1 == r2 && c1 == c2)
        visitQueue.push({{r2 - 1, c2 - 1}, string(1, str1[r1])});
    else
    {
        visitQueue.push({{r1 - 1, c1 - 1}, string(1, str1[r1])});
        visitQueue.push({{r2 - 1, c2 - 1}, string(1, str1[r2])});
    }
}

void findSequence()
{
    if (visitQueue.empty())
        return;

    pair<int, int> currentPosition = visitQueue.front().first;
    string str = visitQueue.front().second;
    int row = currentPosition.first;
    int col = currentPosition.second;
    visitQueue.pop();

    if (cache[row][col] == 0)
    {
        if (!str.empty())
            result[str] = true;

        findSequence();
        return;
    }

    if (cache[row - 1][col] == 0 && cache[row][col - 1] == 0)
        visitQueue.push({{row - 1, col - 1}, str1[row] + str});
    else
    {
        int currentValue = cache[row][col], r = row, c = col;
        bool changeCell = false;

        while (cache[r][c - 1] == currentValue)
            c--;
        if (c != col)
        {
            while (cache[r - 1][c] == currentValue)
                r--;
            visitQueue.push({{r - 1, c - 1}, str1[r] + str});
            changeCell = true;
        }

        r = row;
        c = col;

        while (cache[r - 1][c] == currentValue)
            r--;
        if (r != row)
        {
            while (cache[r][c - 1] == currentValue)
                c--;
            visitQueue.push({{r - 1, c - 1}, str1[r] + str});
            changeCell = true;
        }

        if (!changeCell)
            visitQueue.push({{r - 1, c - 1}, str1[r] + str});
    }

    findSequence();
}

int main()
{
    cin >> str1 >> str2;

    str1 = " " + str1;
    str2 = " " + str2;

    if (str1.size() < str2.size())
    {
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }

    cache = vector<vector<int>>(str1.size(), vector<int>(str2.size(), 0));

    for (long unsigned int i = 1; i < str1.size(); i++)
    {
        for (long unsigned int j = 1; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
                cache[i][j] = cache[i - 1][j - 1] + 1;
            else
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
        }
    }

    pushFirstTime();

    findSequence();

    if (result.empty())
        cout << "khong co xau con chung";
    else
        for (const auto &s : result)
            cout << s.first << '\n';
}
