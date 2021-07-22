/* in case of DAG
 	1. TOPOLOGICAL sort
	2. in order of topo, relax edges
*/

int n, m, q;
vvi adj;
vb vis;
vi par, dist, topo;

void init() {
    adj.resize(n + 1);
    vis.resize(n + 1);
    vis.assign(vis.size(), false);
    par.resize(n + 1);
    par.assign(par.size(), -1);
    dist.resize(n + 1);
    dist.assign(dist.size(), INT_MIN);
}

void dfs(int node) {
    vis[node] = true;
    for (auto x: adj[node]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
    topo.push_back(node);
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int a, b;
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                dfs(i);
        }
        reverse(topo.begin(), topo.end());
        dist[1] = 1;
        for (int i = 0; i < n; i++) {
            int node = topo[i];
            for (auto x: adj[node]) {
                if (dist[x] < dist[node] + 1) {
                    dist[x] = dist[node] + 1;
                    par[x] = node;
                }
            }
        }
        if (par[n] == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            vi ans;
            int temp = n;
            ans.push_back(temp);
            while (par[temp] != -1) {
                ans.push_back(par[temp]);
                temp = par[temp];
            }
            if (ans[ans.size() - 1] != 1) {
                cout << "IMPOSSIBLE\n";
            } else {
                cout << ans.size() << "\n";
                for (int i = ans.size() - 1; i >= 0; i--)
                    cout << ans[i] << " ";
            }
        }
    }
    return EXIT_SUCCESS;
}
