#include <bits/stdc++.h>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define pii pair<ll, ll>

typedef long long ll;

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
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int q, a, b;
        cin >> n;
        depth.resize(n + 1);
        depth.assign(depth.size(), 0);
        x = (int) ceil(log2(n));
        vector<vector<int> > adjList(n + 1);
        vector<vector<int> > dp(n + 1, vector<int>(x + 1, -1));
        // 1 is director

        for (int i = 1; i <= n; i++) {
            cin >> a;
            for (int j = 0; j < a; j++) {
                cin >> b;
                adjList[i].push_back(b);
            }
        }
        dfs(dp, adjList, 1, -1);
        cin >> q;
        int node1, node2;
        cout << "Case " << z << ":\n";
        while (q--) {
            cin >> node1 >> node2;
            int ans = find_lca(node1, node2, dp);
            cout << ans << "\n";
        }
    }
    return EXIT_SUCCESS;
}
