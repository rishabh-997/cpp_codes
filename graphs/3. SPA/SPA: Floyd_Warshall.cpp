// Wyoldd Marshall Algo
n = nodes, m = edges
dist[i][j] = shortest distance of j from i


	ll n, m, query, a, b, c;
        cin >> n >> m >> query;
        vector<vector<ll> > dist(n + 1, vector<ll>(n + 1, 1e18));
        for (ll i = 0; i < m; i++) {
            cin >> a >> b >> c;
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);;
        }
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;

        for (int k = 0; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
