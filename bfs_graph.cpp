vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    vector<int> ans;
    bool visited[adj.size()] = {false};
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        ans.push_back(i);
        for (int j : adj[i])
        {
            if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    return ans;
}