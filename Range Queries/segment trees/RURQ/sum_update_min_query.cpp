#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define vvi vector<vector<ll> >
#define vi vector<ll>
#define int long long
int MOD;

int ADD(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int MUL(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// minimum array, operation array
vi minimum, segment;
int n;

void build_segment_tree(int id = 1, int left = 0, int right = n) {
    /*if (right - left == 1) {
        segment[id] = 0;
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(id * 2, left, mid);
    build_segment_tree(id * 2 + 1, mid, right);
    segment[id] = segment[id * 2] + segment[id * 2 + 1];*/
    segment.assign(segment.size(), 0);
    minimum.assign(minimum.size(), 0);
}

void update_segment_tree(int x, int y, int value, int id = 1, int left = 0, int right = n) {
    // jamai outside
    if (left >= y || right <= x)
        return;
    // jamai inside
    if (left >= x && right <= y) {
        segment[id] += value;
        minimum[id] += value;
        return;
    }
    // jamai beech mein
    int mid = (left + right) / 2;
    update_segment_tree(x, y, value, 2 * id, left, mid);
    update_segment_tree(x, y, value, 2 * id + 1, mid, right);
    minimum[id] = min(minimum[id * 2], minimum[id * 2 + 1]) + segment[id];
}

int query_segment_tree(int x, int y, int id = 1, int left = 0, int right = n) {
    // jamai outside
    if (left >= y || right <= x)
        return INT64_MAX;
    // jamai inside
    if (left >= x && right <= y) {
        return minimum[id];
    }
    // jamai beech mein
    int mid = (left + right) / 2;
    int l = query_segment_tree(x, y, 2 * id, left, mid);
    int r = query_segment_tree(x, y, 2 * id + 1, mid, right);
    return (min(l, r) + segment[id]);
}

int32_t main() {
    fastRead()
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        int query, type;
        cin >> n >> query;
        segment.resize(4 * n + 1);
        minimum.resize(4 * n + 1);
        build_segment_tree();
        for (int i = 0; i < query; i++) {
            cin >> type;
            if (type == 1) {
                int l, r, v;
                cin >> l >> r >> v;
                update_segment_tree(l, r, v);
            } else {
                int l, r;
                cin >> l >> r;
                cout << query_segment_tree(l, r) << "\n";
            }
        }
    }
    return EXIT_SUCCESS;
}
