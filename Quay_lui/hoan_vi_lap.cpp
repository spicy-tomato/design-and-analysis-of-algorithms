/*
 * http://laptrinhonline.club/problem/tichpxsudoku
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Determine character check[i] appeared or did not
 * If check[i] = false -> Did not appear
 *             = true  -> Appeared
 */
bool check[13] = {};

string input;
map<string, bool> result;

void backtrack(const string &str)
{
    if (str.size() == input.size() &&
        result.find(str) == result.end())
    {
        result[str] = true;
    }
    else if (str.size() < input.size())
    {
        for (long unsigned int i = 0; i < input.size(); ++i)
        {
            if (!check[i])
            {
                check[i] = true;
                backtrack(str + input[i]);
                check[i] = false;
            }
        }
    }
}

int main()
{
    cin >> input;

    backtrack("");

    for (auto &item : result)
    {
        if (item.second) // If item.first (saved string) appeared
        {
            cout << item.first << '\n';
        }
    }
}