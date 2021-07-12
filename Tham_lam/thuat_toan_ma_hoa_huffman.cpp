/*
 * http://laptrinhonline.club/problem/tichpxhuffman
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    unordered_map<char, int> frequency, hash;
    auto comparison = [](const pair<string, int> &a, const pair<string, int> &b)
    {
        return a.second > b.second;
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparison)> huffman(comparison);

    cin >> str;

    for (auto c : str)
        frequency[c]++;

    for (auto c : frequency)
        huffman.push({string(1, c.first), c.second});

    int result = 0;

    while (huffman.size() != 1)
    {
        pair<string, int> a, b;
        a = huffman.top();
        huffman.pop();

        b = huffman.top();
        huffman.pop();

        string newString = a.first + b.first;
        huffman.push({newString, a.second + b.second});

        for (auto s : newString)
            hash[s]++;
    }

    for (auto i : hash)
        result += i.second * frequency[i.first];

    cout << result;
}
