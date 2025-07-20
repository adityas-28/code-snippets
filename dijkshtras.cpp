vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int v = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v);
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeWt = it.second;
            int adjNode = it.first;

            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}