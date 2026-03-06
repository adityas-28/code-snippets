const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];

void dfs(int node, int par){
    parent[node][0] = par;

    for(int j = 1; j < LOG; j++)
        parent[node][j] = (parent[node][j-1] == -1 ? -1 : parent[parent[node][j-1]][j-1]);

    for(int child : adj[node]){
        if(child == par) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int kthAncestor(int node, int k){
    for(int j = 0; j < LOG; j++)
        if(k & (1 << j))
            node = (node == -1 ? -1 : parent[node][j]);

    return node;
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    a = kthAncestor(a, depth[a] - depth[b]);

    if(a == b) return a;

    for(int j = LOG - 1; j >= 0; j--){
        if(parent[a][j] != parent[b][j]){
            a = parent[a][j];
            b = parent[b][j];
        }
    }

    return parent[a][0];
}