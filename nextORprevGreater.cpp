#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreater(const vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result(n);

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        result[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return result;
}

vector<int> nextGreater(const vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        result[i] = st.empty() ? -1 : st.top();

        st.push(arr[i]);
    }

    return result;
}

int main() {}