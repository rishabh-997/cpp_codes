
struct edge {
    int u, v, w;
};

int32_t main() {
    fastRead()
    int a, b, c;
    cin >> n >> m;
    vi dist, par;
    dist.resize(n + 1, max_n);
    par.resize(n + 1);
    par.assign(par.size(), -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr.push_back({a, b, c});
    }
    dist[1] = 0;
    int sv;
    // Run n-1 times to find spa if no cycle exists
    for (int i = 0; i < n; i++) {
        sv = -1;
        for (auto edge: arr) {
            if ((dist[edge.v] > dist[edge.u] + edge.w)) {
                dist[edge.v] = dist[edge.u] + edge.w;
                par[edge.v] = edge.u;
                sv = edge.v;
            }
        }
    }
    if (sv == -1)
        cout << "NO";
    else {
        cout << "YES\n";
        vi ans;
	// To find starting vertex in case of many cycles
        for(int i = 1;i<=n;i++)
            sv = par[sv];
        a = sv;
        ans.push_back(sv);
        while (par[a] != sv) {
            ans.push_back(par[a]);
            a = par[a];
        }
        ans.push_back(sv);
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
    }
    return EXIT_SUCCESS;
}
