/*
 * http://laptrinhonline.club/problem/tichpxbupbenga
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, count = 1;
    cin >> n >> k;

    vector<int> dolls = vector<int>(n);

    for (auto &doll : dolls)
        cin >> doll;

    sort(dolls.begin(), dolls.end(), greater<int>());

    long long sum = dolls[0];
    int i = 0, j = 1;

    while (j < n)
    {
        if (dolls[j] + k <= dolls[i])
        {
            i++;
            j++;
        }
        else
        {
            count++;
            sum += dolls[j++];
        }
    }

    cout << count << ' ' << sum;
}
