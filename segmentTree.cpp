#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int idx, int low, int high, vector<int> &arr, vector<int> &seg)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }

    int mid = low + (high - low) / 2;

    buildSegmentTree(2 * idx + 1, low, mid, arr, seg);
    buildSegmentTree(2 * idx + 2, mid + 1, high, arr, seg);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int findMaxQuery(int idx, int low, int high, int l, int r, vector<int> &seg) // low, high for arr; l, r for query
{
    if (low >= l && high <= r) // completely lie inside
    {
        return seg[idx];
    }
    else if ((low < l && high < l) || (low > r && high > r)) // completetly outside
    {
        return INT_MIN;
    }
    else // overlap condition
    {
        int mid = low + (high - low) / 2;

        int left = findMaxQuery(2 * idx + 1, low, mid, l, r, seg);
        int right = findMaxQuery(2 * idx + 2, mid + 1, high, l, r, seg);

        return max(left, right);
    }
}

vector<int> findMaxInRange(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    vector<int> seg(4 * n + 1);

    buildSegmentTree(0, 0, n - 1, arr, seg);

    vector<int> ans;
    for (auto query : queries)
    {
        ans.push_back(findMaxQuery(0, 0, n - 1, query[0], query[1], seg));
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = findMaxInRange(arr, queries);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}