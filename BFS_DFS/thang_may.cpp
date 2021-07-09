/*
 * http://laptrinhonline.club/problem/tichpxthangmay
 */

#include <bits/stdc++.h>

using namespace std;

int floorNumber, up, down, start, _end;
queue<pair<int, int>> Queue;
map<int, bool> visited;

void tryAddMoveToQueue(int currentFloor, int stepCount = 0)
{
    if (!visited[currentFloor])
    {
        visited[currentFloor] = true;
        Queue.push({currentFloor, stepCount});
    }
}

int findSmallestStep()
{
    tryAddMoveToQueue(start);

    while (!Queue.empty())
    {
        int currentPosition = Queue.front().first;
        int count = Queue.front().second;
        Queue.pop();

        if (currentPosition == _end)
        {
            return count;
        }

        if (currentPosition + up <= floorNumber)
        {
            tryAddMoveToQueue(currentPosition + up, count + 1);
        }
        if (currentPosition - down >= 1)
        {
            tryAddMoveToQueue(currentPosition - down, count + 1);
        }
    }

    return -1;
}


int main()
{
    cin >> floorNumber >> up >> down >> start >> _end;

    cout << findSmallestStep();
}
