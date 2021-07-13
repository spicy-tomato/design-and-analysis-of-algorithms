/*
 * http://laptrinhonline.club/problem/tichpxmst
 */

#include <bits/stdc++.h>

#define weight first
#define v1 second.first
#define v2 second.second

using namespace std;

vector<int> parents;

int findParents(int vertex)
{
    if (vertex == parents[vertex])
        return vertex;

    return findParents(parents[vertex]);
}

int main()
{
    int n, m;
    long long result = 0;
    vector<pair<int, pair<int, int>>> edges, edgesInTree;

    cin >> n >> m;
    edges = vector<pair<int, pair<int, int>>>(m);

    for (auto &edge : edges)
        cin >> edge.v1 >> edge.v2 >> edge.weight;
    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++)
        parents.push_back(i);

    for (auto edge : edges)
    {
        int p1 = findParents(edge.v1);
        int p2 = findParents(edge.v2);

        if (p1 != p2)
        {
            edgesInTree.push_back({edge});
            parents[p2] = p1;
        }
    }

    for (auto edge : edgesInTree)
        result += edge.weight;

    cout << result;
}
