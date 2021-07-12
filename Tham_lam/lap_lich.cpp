/*
 * http://laptrinhonline.club/problem/tichpxlaplich
 */

#include <bits/stdc++.h>

#define start first
#define finish second

using namespace std;

int main()
{
    int n, time = 0, result = 0;
    cin >> n;

    vector<pair<int, int>> jobs = vector<pair<int, int>>(n);

    for (auto &job : jobs)
        cin >> job.start >> job.finish;

    sort(jobs.begin(), jobs.end(), [](auto a, auto b)
    {
        return a.finish < b.finish || (a.finish == b.finish && a.start > b.start);
    });

    for (auto & job : jobs)
        if (time < job.start)
        {
            result++;
            time = job.finish;
        }

    cout << result;
}
