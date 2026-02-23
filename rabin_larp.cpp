#include <bits/stdc++.h>
using namespace std;

int PRIME = 101;

bool verify(string &text, string &pattern, int startIndex)
{
    for (int i = 0; i < pattern.size(); i++)
    {
        if (text[startIndex + i] != pattern[i])
            return false;
    }

    return true;
}

long long createHash(string &text, int start, int size)
{
    long long hash = 0;
    for (int i = 0; i < size; i++)
    {
        hash += text[start + i] * pow(PRIME, i);
    }
    return hash;
}

long long updateHash(string &text, long long oldHash, int start, int size)
{
    char prevChar = text[start - 1];
    char newChar = text[start + size - 1];

    long long newHash = (oldHash - prevChar) / PRIME;
    newHash += newChar * pow(PRIME, size - 1);
    return newHash;
}

vector<int> findPattern(string &text, string &pattern)
{
    int patternLength = pattern.length();
    long long patternHash = createHash(pattern, 0, patternLength);
    long long textHash = createHash(text, 0, patternLength);

    vector<int> ans;

    if (textHash == patternHash)
        ans.push_back(0);

    for (int i = 1; i + pattern.size() <= text.size(); i++)
    {
        textHash = updateHash(text, textHash, i, patternLength);

        if (textHash == patternHash)
        {
            if (verify(text, pattern, i))
                ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    string text = "abbbabacbabcabc";
    string pattern = "abc";

    vector<int> ans = findPattern(text, pattern);

    cout << "All Occurences indices: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}