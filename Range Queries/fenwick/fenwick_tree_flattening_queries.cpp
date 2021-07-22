#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);

ll n, q;
vector<ll> value, bit, topo, cunt, pos;
vector<vector<ll> > adjList;

void dfs(ll node, ll par) {
    topo.push_back(node);
    cunt[node] = 1;
    for (auto child:adjList[node]) {
        if (child != par) {
            dfs(child, node);
            cunt[node] += cunt[child];
        }
    }
}

void update_bit(ll position, ll change) {
    while (position <= n) {
        bit[position] += change;
        position = position + (position & (-position));
    }
}

ll sum_query(ll position) {
    ll ans = 0;
    while (position > 0) {
        ans += bit[position];
        position = position & (position - 1);
    }
    return ans;
}

int main() {
    fastRead()
    ll u, v;
    cin >> n >> q;

    value.resize(n + 1);
    bit.resize(n + 1);
    bit.assign(bit.size(), 0);
    adjList.resize(n + 1);
    cunt.resize(n + 1);
    pos.resize(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> value[i];
    for (ll i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1, 0);
    for (ll i = 1; i <= n; i++) {
        pos[topo[i - 1]] = i;
        update_bit(i, value[topo[i - 1]]);
    }

    for (ll i = 0; i < q; i++) {
        cin >> u;
        if (u == 2) {
            // sum
            cin >> v;
            ll ans = sum_query(pos[v] + cunt[v] - 1) - sum_query(pos[v] - 1);
            cout << ans << "\n";
        } else {
            // update
            ll node, val;
            cin >> node >> val;
            update_bit(pos[node], val - value[node]);
            value[node] = val;
        }
    }

    return EXIT_SUCCESS;
}
