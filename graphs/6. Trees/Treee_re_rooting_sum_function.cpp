#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define vvi vector<vector<ll> >
#define vi vector<ll>
#define int long long

vvi adjList;
vi cunt, dp, ans;

void dfs(int node, int par) {
    dp[node] = 0;
    cunt[node] = 1;
    for (auto child: adjList[node]) {
        if (child != par) {
            dfs(child, node);
            dp[node] += dp[child] + cunt[child];
            cunt[node] = cunt[node] + cunt[child];
        }
    }
}

void dfs_re_rooting(int node, int par) {
    ans[node] = dp[node];
    int s1 = cunt[node], t1 = dp[node];
    for (auto child: adjList[node]) {
        if (child == par)
            continue;
        int s2 = cunt[child], t2 = dp[child];

        // Transferring nodes
        cunt[node] -= cunt[child];
        dp[node] -= (dp[child] + cunt[child]);
        cunt[child] += cunt[node];
        dp[child] += (dp[node] + cunt[node]);

        // recusive recalculation
        dfs_re_rooting(child, node);

        // Rollback bitches
        cunt[node] = s1;
        dp[node] = t1;
        cunt[child] = s2;
        dp[child] = t2;
    }
}

int32_t main() {
    fastRead()
    int n, u, v;
    cin >> n;

    adjList.resize(n + 1);
    cunt.resize(n + 1);
    dp.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 0);
    dfs_re_rooting(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return EXIT_SUCCESS;
}
