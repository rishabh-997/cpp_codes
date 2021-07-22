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
int maxx = 1e12;
int minn = -1e12;

int ADD(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int MUL(int a, int b) {
    return (a % MOD * b % MOD) % MOD;
}

int n, m, sum = 0;
vvi adj;
vb vis;
vi rnk, par;

void init() {
    rnk.resize(n + 1);
    par.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        rnk[i] = 1;
        par[i] = i;
    }
}

int find_set(int a) {
    if (a == par[a])
        return a;
    return par[a] = find_set(par[a]);
}

void make_set(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);
    if (pa == pb)
        return;
    if (rnk[a] > rnk[b]) {
        rnk[pa] += rnk[pb];
        par[pb] = pa;
        sum = max(sum, rnk[pa]);
    } else {
        rnk[pb] += rnk[pa];
        par[pa] = pb;
        sum = max(sum, rnk[pb]);
    }
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int a, b;
        cin >> n >> m;
        init();
        int nodes = n;
        while (m--) {
            cin >> a >> b;
            if (find_set(a) == find_set(b)) {
                cout << nodes << " " << sum;
            } else {
                make_set(a, b);
                nodes--;
                cout << nodes << " " << sum;
            }
            cout << "\n";
        }
    }
    return EXIT_SUCCESS;
}


