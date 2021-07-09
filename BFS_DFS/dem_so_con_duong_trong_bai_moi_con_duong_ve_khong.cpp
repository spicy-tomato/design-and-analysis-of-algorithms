/*
 * http://laptrinhonline.club/problem/tichpxzerodem
 */

#include <bits/stdc++.h>

using namespace std;
const unsigned long long module = 1000000007;

unsigned long long countPath(unordered_map<int, unsigned long long>& travelled, int current)
{
    auto currentPathCount = travelled[current];
    if (currentPathCount != 0)
    {
        return currentPathCount;
    }

    for (int a = 1; a * a <= current; a++)
    {
        if (current % a == 0)
        {
            int b = current / a;
            int m = (a - 1) * (b + 1);
            currentPathCount = (currentPathCount + countPath(travelled, m) % module) % module;
        }
    }

    travelled[current] = currentPathCount;
    return currentPathCount;
}

int main(){
    int test, n;
    cin >> test;

    unordered_map<int, unsigned long long> travelled;
    travelled[0] = 1;

    while (test--)
    {
        cin >> n;
        cout << countPath(travelled, n) << '\n';
    }
}
