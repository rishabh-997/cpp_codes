// It will give distance between any two nodes in log(n) time.
// Can be done via DFS but this will take O(n) per query


int n, x;
vector<int> depth;

void dfs(vector<vector<int> > &dp, vector<vector<int> > &adjList, int source, int parent) {
    dp[source][0] = parent;
    for (int i = 1; i <= x && source != 1; i++) {
        if (dp[source][i - 1] != -1)
            dp[source][i] = dp[dp[source][i - 1]][i - 1];
    }
    for (auto child: adjList[source]) {
        if (child != parent) {
            depth[child] = 1 + depth[source];
            dfs(dp, adjList, child, source);
        }
    }
}

int find_parent(int node, int k, vector<vector<int> > &dp) {
    for (int i = x; i >= 0; i--) {
        if ((1 << i) & k) {
            node = dp[node][i];
            if (node == -1)
                return -1;
        }
    }
    return node;
}

int find_lca(ll a, ll b, vector<vector<int> > &dp) {
    if (depth[b] < depth[a])
        swap(a, b);
    int c = depth[b] - depth[a];
    b = find_parent(b, c, dp);
    if (a == b)
        return a;
    for (int i = x; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i], b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main() {
    fastRead()
    int t;
    //cin >> t;
    t = 1;
    for (int z = 1; z <= t; z++) {
        int q, a, b;
        cin >> n >> q;

        x = (int) ceil(log2(n));
        depth.resize(n + 1);
        depth.assign(depth.size(), 0);
        vector<vector<int> > adjList(n + 1);
        vector<vector<int> > dp(n + 1, vector<int>(x + 1, -1));

        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        dfs(dp, adjList, 1, -1);

        int node1, node2;
        while (q--) {
            cin >> node1 >> node2;
            int ans = depth[node1] + depth[node2] - 2 * depth[find_lca(node1, node2, dp)];
            cout << ans << "\n";
        }
    }
    return EXIT_SUCCESS;
}
