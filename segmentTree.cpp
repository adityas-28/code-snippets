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

void updateSegmentTree(int idx, int low, int high, int pos, int val, vector<int> &seg)
{
    if (low == high)
    {
        seg[idx] = val;
        return;
    }

    int mid = low + (high - low) / 2;

    if (pos <= mid)
        updateSegmentTree(2 * idx + 1, low, mid, pos, val, seg);
    else
        updateSegmentTree(2 * idx + 2, mid + 1, high, pos, val, seg);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int findMaxQuery(int idx, int low, int high, int l, int r, vector<int> &seg) // low, high for arr; l, r for query
{
    if (low >= l && high <= r) // completely lie inside
        return seg[idx];

    else if (high < l || low > r) // completetly outside
        return INT_MIN;

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