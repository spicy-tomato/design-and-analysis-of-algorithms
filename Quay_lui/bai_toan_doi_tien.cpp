/*
 * http://laptrinhonline.club/problem/tichpxdoitien
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> denominations, cache;

int findMin(int money)
{
    if (cache[money] != INT_MAX) return cache[money];

    int minCount = INT_MAX;
    for (auto item : denominations)
    {
        if (money  < item) break;
        if (money == item) return 1;

        int m = findMin(money - item);
        if (m != INT_MAX)
            minCount = min(minCount, m + 1);
    }

    cache[money] = minCount;
    return minCount;
}

int main()
{
    int n, q, result;
    int largestQuery = 0;
    vector<int> queries;

    cin >> n >> q;
    denominations = vector<int>(n);
    queries = vector<int>(q);

    for (auto &i : denominations)
        cin >> i;

    for (auto &query : queries)
    {
        cin >> query;
        largestQuery = max(query, largestQuery);
    }

    cache = vector<int>(largestQuery + 5, INT_MAX);

    sort(denominations.begin(), denominations.end());

    for (auto &i : queries)
    {
        result = findMin(i);
        cout << (result == INT_MAX ? -1 : result) << '\n';
    }
}