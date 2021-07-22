#include <bits/stdc++.h>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define pii pair<ll, ll>

typedef long long ll;

struct st {
    ll node;
    ll offers;
    ll dist;
};

struct compare {
    bool operator()(st one, st two) {
        return one.dist > two.dist;
    }
};

int main() {
    fastRead()
    ll t;
    //cin >> t;
    t = 1;
    while (t--) {
        ll n, m, k, a, b, c;
        cin >> n >> m;
        k = 1;
        vector<vector<pii > > adjList(n);
        for (ll i = 0; i < m; i++) {
            cin >> a >> b >> c;
            a--, b--;
            adjList[a].push_back({b, c});
        }

        vector<vector<ll> > dist(n, vector<ll>(k + 1, INT64_MAX));
        priority_queue<st, vector<st>, compare> pq;
        pq.push({0, k, 0});
        dist[0][k] = 0;
        // zeroth node par k offers hain with minimum distance zero

        while (!pq.empty()) {
            st vertex = pq.top();
            pq.pop();
            ll node = vertex.node;
            ll d = vertex.dist;
            ll offers = vertex.offers;
            if (vertex.dist > dist[node][offers])
                continue;
            for (auto child: adjList[node]) {
                int to_vertex = child.first;
                int cost = child.second;
                if (offers > 0) {
                    if (dist[to_vertex][offers - 1] > (d + cost / 2)) {
                        dist[to_vertex][offers - 1] = d + cost / 2;
                        pq.push({to_vertex, offers - 1, d + cost / 2});
                    }
                }
                if (dist[to_vertex][offers] > d + cost) {
                    dist[to_vertex][offers] = d + cost;
                    pq.push({to_vertex, offers, d + cost});
                }
            }
        }

        ll ans = INT64_MAX;
        for (int j = 0; j <= k; j++)
            ans = min(ans, dist[n - 1][j]);
        cout << ans << "\n";
    }
    return EXIT_SUCCESS;
}
