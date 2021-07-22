#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define vpi vector<pi>
#define vvpi vector<vector<pi> >
int MOD = 1000000007;
int maxx = 1e16;
int minn = -1e16;

int ADD(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int MUL(int a, int b) {
    return (a % MOD * b % MOD) % MOD;
}

int n, m, q;
vvpi adj;
vb vis;
vi par, topo;

void init() {
    adj.resize(n + 1);
    vis.resize(n + 1);
    vis.assign(vis.size(), false);
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int a, b, c;
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        priority_queue<pi, vector<pi >, greater<> > pq;
        pq.push({0, 1});

        vi dist(n + 1, maxx), cunt(n + 1, 0), minf(n + 1, maxx), maxf(n + 1, minn);
        dist[1] = 0;
        cunt[1] = 1;
        minf[1] = 0;
        maxf[1] = 0;
        while (!pq.empty()) {
            pi p = pq.top();
            pq.pop();
            if (vis[p.second])
                continue;
            vis[p.second] = true;
            int u = p.second, d = p.first;
            for (auto x: adj[u]) {
                int v = x.first, w = x.second;
                if (dist[v] == dist[u] + w) {
                    cunt[v] = ADD(cunt[v], cunt[u]);
                    minf[v] = min(minf[v], 1 + minf[u]);
                    maxf[v] = max(maxf[v], 1 + maxf[u]);
                    pq.push({dist[v], v});
                } else if (dist[v] > dist[u] + w) {
                    cunt[v] = cunt[u];
                    dist[v] = dist[u] + w;
                    minf[v] = 1 + minf[u];
                    maxf[v] = 1 + maxf[u];
                    pq.push({dist[v], v});
                }
            }
        }
        cout << dist[n] << " " << cunt[n] << " " << minf[n] << " " << maxf[n];
    }
    return EXIT_SUCCESS;
}
