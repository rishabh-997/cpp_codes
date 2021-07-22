#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define vvi vector<vector<ll> >
#define vi vector<ll>
#define int long long
int MOD;

struct item {
    int a1, a2, a3, a4;

    item() {
        a1 = 1, a2 = 0, a3 = 0, a4 = 1;
    }
};

int ADD(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int MUL(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

vi arr, segment, ans;
int n;

void build_segment_tree(int id = 1, int left = 0, int right = n) {
    if (right - left == 1) {
        segment[id] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(id * 2, left, mid);
    build_segment_tree(id * 2 + 1, mid, right);
    segment[id] = segment[id * 2] + segment[id * 2 + 1];
}

void update_segment_tree(int pos, int id = 1, int left = 0, int right = n) {
    if (right - left == 1) {
        segment[id] = 0;
        return;
    }
    int mid = (left + right) / 2;
    if (pos < mid)
        update_segment_tree(pos, id * 2, left, mid);
    else
        update_segment_tree(pos, id * 2 + 1, mid, right);
    segment[id] = segment[2 * id] + segment[1 + 2 * id];
}

int query_segment_tree(int value, int id = 1, int lx = 0, int rx = n) {
    if (rx - lx == 1) {
        return lx;
    }
    int mid = (lx + rx) / 2;
    if (segment[2 * id] >= value)
        return query_segment_tree(value, 2 * id, lx, mid);
    else
        return query_segment_tree(value - segment[2 * id], 2 * id + 1, mid, rx);
}

int32_t main() {
    fastRead()
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        cin >> n;
        arr.resize(n);
        ans.resize(n);
        segment.resize(4 * n + 1);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        build_segment_tree();
        for (int i = n - 1; i >= 0; i--) {
            int q = query_segment_tree(segment[1] - arr[i]);
            ans[i] = q + 1;
            update_segment_tree(q);
        }
        for (auto x:ans)
            cout << x << " ";
    }
    return EXIT_SUCCESS;
}


