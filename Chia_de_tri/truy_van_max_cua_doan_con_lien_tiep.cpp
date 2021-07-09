/*
 * http://laptrinhonline.club/problem/tichpxtruyvanmax
 */

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> id, Q;

void make(int left = 0,
          int right = n - 1,
          int index = 1)
{
    Q[index] = 0;

    if (left == right)
    {
        id[left] = index;
    }
    else
    {
        int mid = (left + right) / 2;
        make(left   , mid  , 2 * index);
        make(mid + 1, right, 2 * index + 1);
    }
}

void update(int i, int value)
{
    int index = id[i];
    Q[index] = value;

    while (index > 1)
    {
        index /= 2;
        Q[index] = max(
                Q[2 * index],
                Q[2 * index + 1]);
    }
}

int findMax(int i,
            int j,
            int left = 0,
            int right = n - 1,
            int index = 1)
{
    if (i == left && j == right)
    {
        return Q[index];
    }

    int mid = (left + right) / 2, result;

    if (mid < i)
    {
        result = findMax(i,
                         j,
                         mid + 1,
                         right,
                         2 * index + 1);
    }
    else if (j <= mid)
    {
        result = findMax(i,
                         j,
                         left,
                         mid,
                         2 * index);
    }
    else
    {
        result = max(
                findMax(i, mid, left, mid, 2 * index),
                findMax(mid + 1, j, mid + 1, right, 2 * index + 1)
        );
    }

    return result;
}

int main()
{
    int m, tmp, left, right;
    cin >> n >> m;

    id = vector<int>(n);
    Q  = vector<int>(4 * n);

    make();

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        update(i, tmp);
    }

    while (m--)
    {
        cin >> left >> right;
        cout << findMax(left - 1, right - 1) << '\n';
    }
}
