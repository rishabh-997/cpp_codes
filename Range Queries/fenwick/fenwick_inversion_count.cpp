#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pi>
int mod = 998244353;

void build(vi &bit, int n) {
    for (int i = 1; i <= n; i++) {
        int par = i + (i & (-i));
        if (par <= n)
            bit[par] += bit[i];
    }
}

void update(int pos, int value, vi &bit, int n) {
    while (pos <= n) {
        bit[pos] = bit[pos] + value;
        pos = pos + (pos & (-pos));
    }
}

int query(vi &bit, int a) {
    int ans = 0;
    while (a > 0) {
        ans = ans + bit[a];
        a = a & (a - 1);
    }
    return ans;
}

int32_t main() {
    fastRead()
    int tests = 1;
    cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int n, a, ans = 0;
        cin >> n;
        int size = 1e7 + 3;
        vi bit(1e7 + 5, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a;
            update(a, 1, bit, size);
            ans = ans + query(bit, size) - query(bit, a);
        }
        cout << ans << "\n";
    }
    return EXIT_SUCCESS;
}
