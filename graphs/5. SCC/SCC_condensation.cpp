#include <bits/stdc++.h>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define pii pair<ll, ll>

typedef long long ll;

vector<int> component;
vector<vector<int> > adjList;
vector<pii > edges;
vector<vector<int> > adjListReversed;
vector<ll> cost;
vector<bool> visited;
vector<int> topo;
// condensed vectors
int id = 1;
vector<vector<int> > connected_components;
vector<ll> cost_condensed;
vector<int> id_condensed;
vector<int> topo_condensed;
vector<vector<int> > adjListCondensed;

void dfs_topological_sort(int n) {
    visited[n] = true;
    for (auto child: adjList[n]) {
        if (!visited[child])
            dfs_topological_sort(child);
    }
    topo.push_back(n);
}

void dfs(int n) {
    visited[n] = true;
    for (auto child: adjListReversed[n]) {
        if (!visited[child])
            dfs(child);
    }
    id_condensed[n] = id;
    cost_condensed[id] += cost[n];
    component.push_back(n);
}

int main() {
    fastRead()
    int n, m, a, b;
    cin >> n >> m;

    adjList.resize(n + 1);
    adjListReversed.resize(n + 1);
    adjListCondensed.resize(n + 1);
    visited.resize(n + 1, false);
    cost.resize(n + 1);
    edges.resize(m);

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjListReversed[b].push_back(a);
        edges[i] = {a, b};
    }

    // 1. topological sort of original array
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs_topological_sort(i);
    }
    reverse(topo.begin(), topo.end());

    // 2. Apply dfs on reversed graph in topological order of first graph
    visited.assign(visited.size(), false);
    cost_condensed.assign(n + 1, 0);
    id_condensed.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int node = topo[i];
        if (!visited[node]) {
            component.clear();
            dfs(node);
            connected_components.push_back(component);
            id++;
        }
    }

    // 3. Creating topo sort for condensed graph
    vector<bool> v(id, false);
    for (int i = 0; i < n; i++) {
        int index = id_condensed[topo[i]];
        if (!v[index]) {
            topo_condensed.push_back(index);
            v[index] = true;
        }
    }

    // 4. Creating Condensed graph with edges
    for (auto edge:edges) {
        int u_id = id_condensed[edge.first];
        int v_id = id_condensed[edge.second];
        if (u_id != v_id)
            adjListCondensed[u_id].push_back(v_id);
    }
/**
* Upar condensed ho chuka, ab up par operations pelo
*/
    // 5. reverse condensed sort so we select the most visited city first
    reverse(topo_condensed.begin(), topo_condensed.end());

    // 6. DP to visit cities one by one
    vector<ll> ans(n + 1, 0);
    for (auto par: topo_condensed) {
        for (auto child: adjListCondensed[par]) {
            ans[par] = max(ans[par], ans[child]);
        }
        ans[par] += cost_condensed[par];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[id_condensed[i]] << " ";
    }

    return EXIT_SUCCESS;
}

