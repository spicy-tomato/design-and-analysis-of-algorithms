/*
 * http://laptrinhonline.club/problem/ssptrees
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> trees = vector<int>(n);

    for (auto &tree : trees)
        cin >> tree;

    sort(trees.begin(), trees.end(), greater<int>());

    int daysToGrow = trees[0];

    for (auto &tree : trees)
        daysToGrow = max(tree, --daysToGrow);

    cout << trees.size() + daysToGrow + 1;
}
