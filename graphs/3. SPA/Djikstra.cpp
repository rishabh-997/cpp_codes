// DJIKSTRA ALGORITHM
// 1. Directed graph ke liye

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
 
int ADD(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}
 
int MUL(int a, int b) {
    return (a % MOD * b % MOD) % MOD;
}
 
int n, m;
vvpi adj;
vb vis;
vi par, depth, dist;
 
void init() {
    adj.resize(n + 1);
    vis.resize(n + 1);
    vis.assign(vis.size(), false);
    dist.resize(n + 1);
    dist.assign(dist.size(), 1e14);
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
        dist[1] = 0;
        priority_queue<pi, vector<pi >, greater<> > pq;
        pq.push({0, 1});
        while (!pq.empty()) {
            pi temp = pq.top();
            pq.pop();
            int u = temp.second;
            if (vis[u])
                continue;
            vis[u] = true;
            for (auto x: adj[u]) {
                int v = x.first;
                int w = x.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << dist[i] << " ";
    }
    return EXIT_SUCCESS;
}







