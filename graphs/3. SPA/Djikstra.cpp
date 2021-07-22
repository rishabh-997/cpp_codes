// DJIKSTRA ALGORITHM
// 1. Directed graph ke liye

#define pii pair<ll, ll>
typedef long long ll;

	ll n, m, a, b, c;
        cin >> n >> m;
        vector<vector<pii > > adjList(n + 1);
        for (ll i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adjList[a].push_back({b, c});
        }

        vector<ll> dist(n + 1, INT64_MAX);
        vector<bool> visited(n + 1, false);
        dist[1] = 0;
        set<pii > st;
        st.insert({0, 1});

        while (!st.empty()) {
            ll top = (*st.begin()).second;
            st.erase(st.begin());
            if (visited[top])
                continue;
            visited[top] = true;
            for (auto child: adjList[top]) {
                ll v = child.first;
                ll w = child.second;
                if (dist[v] > dist[top] + w) {
                    dist[v] = dist[top] + w;
                    st.insert({dist[v], v});
                }
            }
        }
