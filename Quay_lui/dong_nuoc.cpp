/*
 * http://laptrinhonline.club/problem/tichpxdongnuoc
 */

#include <bits/stdc++.h>

using namespace std;

int m, n, k;
long long stepCount;

/*
 * Save states of bottles
 * saved.first: (pair): State
 *      saved.first.first : State of the first bottle
 *      saved.first.second: State of the second bottle
 * save.second: (bool): appeared or not?
 */
map<pair<int, int>, bool> saved;

/*
 * Save states which we need to check later
 * stepQueue.first: (pair): State
 *      stepQueue[i].first : State of the first bottle
 *      stepQueue[i].second: State of the second bottle
 * stepQueue.second: (long long): Minimum steps to reach current state
 */
queue<pair<pair<int, int>, long long>> stepQueue;

void addToQueue(pair<int, int> p)
{
    if (!saved[p])
    {
        saved[p] = true;
        stepQueue.push({p, stepCount});
    }
}

void bfs()
{
    saved[{0, 0}] = true;
    stepQueue.push({{0, 0}, 0});

    while (!stepQueue.empty())
    {
        pair<int, int> currentState = stepQueue.front().first;
        stepCount = stepQueue.front().second + 1;
        stepQueue.pop();

        // Found result!
        if (currentState.first == k || currentState.second == k)
        {
            cout << stepCount - 1;
            return;
        }

        // Pour all water in the first bottle
        addToQueue({0, currentState.second});

        // Pour all water in the second bottle
        addToQueue({currentState.first, 0});

        // Fill water in the first bottle
        addToQueue({m, currentState.second});

        // Fill water in the second bottle
        addToQueue({currentState.first, n});

        // Pour water from second to first bottle
        if (currentState.first + currentState.second <= m)
            // If second bottle will empty
            addToQueue({currentState.first + currentState.second, 0});
        else
            // If second bottle will not empty
            addToQueue({m, currentState.first + currentState.second - m});

        // Pour water from first to second bottle
        if (currentState.first + currentState.second <= n)
            // If second bottle will empty
            addToQueue({0, currentState.first + currentState.second});
        else
            // If second bottle will not empty
            addToQueue({currentState.first + currentState.second - n, n});
    }
}

int main()
{
    cin >> m >> n >> k;

    if (k % __gcd(m, n))
        cout << "Khong dong duoc nuoc";
    else
        bfs();
}