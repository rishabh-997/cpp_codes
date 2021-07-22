#include <bits/stdc++.h>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define pii pair<ll, ll>

typedef long long ll;

int n, x;

void dfs(vector<vector<int> > &dp, vector<vector<int> > &adjList, int source, int parent) {
    dp[source][0] = parent;
    for (int i = 1; i <= x && source != 1; i++) {
        if (dp[source][i - 1] != -1)
            dp[source][i] = dp[dp[source][i - 1]][i - 1];
    }
    for (auto child: adjList[source]) {
        if (child != parent) {
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

int main() {
    fastRead()
    int q, a;
    cin >> n >> q;
    x = (int) ceil(log2(n));
    vector<vector<int> > adjList(n + 1);
    vector<vector<int> > dp(n + 1, vector<int>(x + 1, -1));
    // 1 is director

    for (int i = 2; i <= n; i++) {
        cin >> a;
        adjList[a].push_back(i);
    }
    dfs(dp, adjList, 1, -1);
    int node, k;
    while (q--) {
        cin >> node >> k;
        int ans = find_parent(node, k, dp);
        cout << ans << "\n";
    }
    return EXIT_SUCCESS;
}
