void dfs(int node, vector<vector<int>> &adj, bool visited[], vector<int> &list)
{
    visited[node] = true;
    list.push_back(node);
    for (int i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, list);
        }
    }
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    bool visited[adj.size()] = {false};
    visited[0] = true;
    vector<int> list;
    dfs(0, adj, visited, list);
    return list;
}