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

item add_array(item a, item b) {
    item c;
    c.a1 = ADD(MUL(a.a1, b.a1), MUL(a.a2, b.a3));
    c.a2 = ADD(MUL(a.a1, b.a2), MUL(a.a2, b.a4));
    c.a3 = ADD(MUL(a.a3, b.a1), MUL(a.a4, b.a3));
    c.a4 = ADD(MUL(a.a3, b.a2), MUL(a.a4, b.a4));
    return c;
}

item neutral_item() {
    item x;
    return x;
}

vector<item> arr, segment;
int r, n, query;

void build_segment_tree(int id = 1, int left = 0, int right = n) {
    if (right - left == 1) {
        segment[id] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(id * 2, left, mid);
    build_segment_tree(id * 2 + 1, mid, right);
    segment[id] = add_array(segment[id * 2], segment[id * 2 + 1]);
}

// (starting index, ending index, id of node, start of node, end of node)
// [x, y)
item query_segment_tree(int x, int y, int id = 1, int lx = 0, int rx = n) {
    // [x,y) lies entirely outside [lx, ry)
    if (rx <= x || lx >= y) {
        item temp = neutral_item();
        return temp;
    }

    // [x,y) lies entirely inside [lx, ry)
    if (lx >= x && rx <= y)
        return segment[id];

    // [x,y) lies partially inside [lx, ry)
    int mid = (lx + rx) / 2;
    item left = query_segment_tree(x, y, 2 * id, lx, mid);
    item right = query_segment_tree(x, y, 2 * id + 1, mid, rx);
    return add_array(left, right);
}

int32_t main() {
    fastRead()
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        cin >> r >> n >> query;
        MOD = r;
        arr.resize(n);
        segment.resize(4 * n + 1);
        for (int i = 0; i < n; i++) {
            item x;
            cin >> x.a1 >> x.a2 >> x.a3 >> x.a4;
            arr[i] = x;
        }
        build_segment_tree();
        int a, b;
        while (query--) {
            cin >> a >> b;
            item ans = query_segment_tree(a - 1, b);
            cout << ans.a1 << " " << ans.a2 << "\n" << ans.a3 << " " << ans.a4 << "\n\n";
        }
    }
    return EXIT_SUCCESS;
}
