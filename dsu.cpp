class DisjointSet
{
private:
    vector<int> rank, size, parent;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int u_p = findUParent(u);
        int v_p = findUParent(v);

        if (u_p == v_p)
            return;

        if (rank[u_p] > rank[v_p])
        {
            parent[v_p] = u_p;
        }

        if (rank[u_p] < rank[v_p])
        {
            parent[u_p] = v_p;
        }

        else
        {
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int u_p = findUParent(u);
        int v_p = findUParent(v);

        if (u_p == v_p)
            return;

        if (size[u_p] > size[v_p])
        {
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }

        else
        {
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
    }

    int findSize(int n)
    {
        return size[findUParent(n)];
    }
};