#include <bits/stdc++.h>
using namespace std;

vector<int> createLps(string s)
{
    int n = s.size();

    int i = 0; // prefix ptr
    int j = 1; // suffix ptr
    vector<int> lps(n, 0);

    while (j < n)
    {
        if (s[i] == s[j]) // if matches
        {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i == 0) // if i is at zero then just set lps[j] as 0
            {
                lps[j] = 0;
                j++;
            }
            else // move i pointer to the previous matching pointer
            {
                i = lps[i - 1];
            }
        }
    }
    // for (int i : lps)
    //     cout << i << " ";
    // cout << endl;

    return lps;
}

vector<int> kmp(string s, string pat)
{
    int n = s.size();
    int p = pat.size();

    vector<int> lps = createLps(pat);

    vector<int> ans;
    int j = 0; // pointer for matching pattern
    int i = 0; // pointer for matching string

    while (i < n) // loop {O(n)} for string matching
    {
        if (s[i] == pat[j])
        {
            i++;
            j++;

            if (j == p)
            {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return ans;
}

int main()
{
    string s = "cbdcbcbcacbcaacbc";
    string pat = "cbc";

    vector<int> ans = kmp(s, pat);
    vector<int> lps = createLps("AAACAAAAAC");
    for (int i : lps)
    {
        cout << i << " ";
    }
    cout << endl
         << 1;

    // cout
    //     << "Ans array : " << endl;
    // for (int i : ans)
    //     cout << i << " ";
    // cout << endl;

    return 0;
}