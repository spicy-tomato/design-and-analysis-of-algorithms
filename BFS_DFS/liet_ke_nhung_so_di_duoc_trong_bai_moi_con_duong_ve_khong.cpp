/*
 * http://laptrinhonline.club/problem/tichpxlietkezero
 */

#include <bits/stdc++.h>

using namespace std;

int n;
map<int, bool> travelledNodes;
queue<int> willTravelNodes;

void markTravelled(int node)
{
    willTravelNodes.push(node);
    travelledNodes[node] = true;
}

vector<int> listNodes()
{
    markTravelled(n);

    while (!willTravelNodes.empty())
    {
        int current = willTravelNodes.front();
        willTravelNodes.pop();

        for (int a = 1; a * a <= current; a++)
        {
            if (current % a == 0)
            {
                int b = current / a;
                int m = (a - 1) * (b + 1);

                if (!travelledNodes[m])
                {
                    markTravelled(m);
                }
            }
        }
    }

    vector<int> result;

    for (auto const &node : travelledNodes)
    {
        result.push_back(node.first);
    }

    return result;
}

int main()
{
    cin >> n;

    for (auto node : listNodes())
    {
        cout << node << ' ';
    }
};
