#include <bits/stdc++.h>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define pii pair<int, int>
#define int long long

const int max_n = 1e17;
const int min_n = -1e17;
const int MOD = 1e9 + 7;

vector<vector<int> > adjList, adjListRev, connected;
vector<int> topo, arr, dp;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (auto child: adjList[node]) {
        if (!visited[child])
            dfs(child);
    }
    topo.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    for (auto child: adjListRev[node]) {
        if (!visited[child])
            dfs2(child);
    }
    arr.push_back(node);
}

int32_t main() {
    fastRead()
    int n, m, a, b;
    cin >> n >> m;
    adjList.resize(n + 1);
    adjListRev.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjListRev[b].push_back(a);
    }
    visited.resize(n + 1);
    visited.assign(visited.size(), false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());
    visited.assign(visited.size(), false);
    for (auto x: topo) {
        if (!visited[x]) {
            dfs2(x);
            connected.push_back(arr);
            arr.clear();
        }
    }

    dp.resize(n + 1);
    dp.assign(dp.size(), 0);
    int pos = 1;
    for (const auto &x: connected) {
        for (auto node:x) {
            dp[node] = pos;
        }
        pos++;
    }
    cout << pos - 1 << "\n";
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    return EXIT_SUCCESS;
}
