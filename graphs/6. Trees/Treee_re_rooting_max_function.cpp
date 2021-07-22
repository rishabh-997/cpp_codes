#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define vvi vector<vector<ll> >
#define vi vector<ll>
#define int int

vvi adjList;
vi dp, ans, weight;

void dfs(int node, int par) {
    dp[node] = 0;
    for (auto child: adjList[node]) {
        if (child == par)
            continue;
        dfs(child, node);
        dp[node] = max(dp[node], dp[child]);
    }
    dp[node] += weight[node];
}

void dfs_re_rooting(int node, int par) {
    ans[node] = dp[node];
    // pre computation ki bakchodi
    vector<int> prefix, suffix;
    for (auto child:adjList[node]) {
        if (par == child)
            continue;
        prefix.push_back(dp[child]);
        suffix.push_back(dp[child]);
    }
    int size = prefix.size();
    for (int i = 1; i < size; i++)
        prefix[i] = max(prefix[i], prefix[i - 1]);
    for (int i = size - 2; i >= 0; i--)
        suffix[i] = max(suffix[i], suffix[i + 1]);

    int pos = 0, t1 = dp[node];
    for (auto child:adjList[node]) {
        if (child == par)
            continue;
        int t2 = dp[child], l = 0, r = 0;
        if (pos > 0)
            l = prefix[pos - 1];
        if (pos < size - 1)
            r = suffix[pos + 1];

        // re rooting node to child
        dp[node] = max(l, r) + weight[node];
        if (par != 0)
            dp[node] = max(dp[node], dp[par] + weight[node]);
        dp[child] = max(dp[child], dp[node] + weight[child]);

        // recusive recalculation
        dfs_re_rooting(child, node);

        // Rollback bitches
        dp[node] = t1;
        dp[child] = t2;
        pos++;
    }
}


int32_t main() {
    fastRead()
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        cin >> n;

        adjList.clear();
        weight.clear();
        dp.clear();
        ans.clear();
        adjList.resize(n + 1);
        weight.resize(n + 1);
        dp.resize(n + 1);
        ans.resize(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> weight[i];

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(1, 0);
        dfs_re_rooting(1, 0);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return EXIT_SUCCESS;
}
