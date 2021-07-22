int n, m;
vvi adj;
vb vis;
vi par;
 
int sv, ev;
 
// traversal to find cycle
bool dfs(int node, int parent) {
    vis[node] = true;
    par[node] = parent;
    for (auto x: adj[node]) {
        if (x == parent)
            continue;
        if (vis[x]) {
            sv = node;
            ev = x;
            return true;
        }
        if (!vis[x]) {
            if (dfs(x, node))
                return true;
        }
    }
    return false;
}
 
// Connected Components
bool check() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}
 
int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        cin >> n >> m;
        adj.resize(n + 1);
        vis.resize(n + 1);
        par.resize(n + 1);
        vis.assign(vis.size(), false);
        par.assign(par.size(), -1);
 
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
 
        if (!check()) {
            cout << "IMPOSSIBLE";
            return EXIT_SUCCESS;
        }

// PRINTING
        vector<int> ans;
        ans.push_back(ev);
        while (sv != ev) {
            ans.push_back(sv);
            sv = par[sv];
        }
        ans.push_back(sv);
        cout << ans.size() << "\n";
        for (auto x: ans)
            cout << x << " ";
    }
    return EXIT_SUCCESS;
}

