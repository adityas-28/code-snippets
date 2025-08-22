#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int bit[N];

void update(int i, int x)
{
    for (; i < N; i += (i & -i))
        bit[i] += x;
}

int sum(int i)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q; // size of array and number of queries

    // Input array and build BIT
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i]); // build BIT
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Point update: add x at index i
            int i, x;
            cin >> i >> x;
            update(i, x);
        } else if (type == 2) {
            // Range query: sum from l to r
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l-1) << "\n";
        }
    }
}