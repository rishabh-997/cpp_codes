int n, m;
vvi adj;
vi vis;
vi par, depth;

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int a, b;
        cin >> n >> m;
        adj.resize(n + 1);
        vis.resize(n + 1);
        vis.assign(vis.size(), false);
        par.resize(n + 1);
        par.assign(par.size(), -1);
        depth.resize(n + 1);
        depth.assign(depth.size(), 0);

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        q.push(1);
        depth[1] = 1;
        vis[1] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto x: adj[node]) {
                if (!vis[x]) {
                    depth[x] = 1 + depth[node];
                    par[x] = node;
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        if (par[n] == -1)
            cout << "IMPOSSIBLE\n";
        else {
            vi ans;
            int temp = n;
            ans.push_back(temp);
            while (temp != -1) {
                temp = par[temp];
                ans.push_back(temp);
            }
            cout << depth[n] << '\n';
            for (int i = ans.size() - 2; i >= 0; i--)
                cout << ans[i] << " ";
        }
    }
    return EXIT_SUCCESS;
}
