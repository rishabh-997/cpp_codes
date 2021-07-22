#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
#define vvi vector<vector<ll> >
#define vpi vector<pi>
#define vi vector<ll>
#define pi pair<ll, int>

vi arr, segment;
int n;

void build_segment_tree(int id = 1, int left = 0, int right = n) {
    if (right - left == 1) {
        segment[id] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    // left sub-tree
    build_segment_tree(id * 2, left, mid);
    // right sub-tree
    build_segment_tree(id * 2 + 1, mid, right);
    segment[id] = max(segment[id * 2], segment[id * 2 + 1]);
}

void update_segment_tree(int pos, int value, int id = 1, int lx = 0, int rx = n) {
    if (rx - lx == 1) {
        arr[pos] = value;
        segment[id] = value;
        return;
    }
    int mid = (lx + rx) / 2;
    if (pos < mid)
        update_segment_tree(pos, value, id * 2, lx, mid);
    else
        update_segment_tree(pos, value, 2 * id + 1, mid, rx);
    segment[id] = max(segment[id * 2], segment[id * 2 + 1]);
}

int query_segment_tree(int value, int least, int id = 1, int lx = 0, int rx = n) {
    if (segment[id] < value)
        return -1;
    if (rx <= least)
        return -1;
    if (rx - lx == 1)
        return lx;
    int mid = (lx + rx) / 2;
    int ans = query_segment_tree(value, least, 2 * id, lx, mid);
    if (ans == -1)
        ans = query_segment_tree(value, least, 2 * id + 1, mid, rx);
    return ans;
}

int32_t main() {
    fastRead()
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        int query, type, pos, value;
        cin >> n >> query;
        arr.resize(n);
        segment.resize(4 * n + 1);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        build_segment_tree();
        while (query--) {
            cin >> type >> pos >> value;
            if (type == 1) {
                update_segment_tree(pos, value);
            } else {
                cout << query_segment_tree(pos, value) << "\n";
            }
        }
    }
    return EXIT_SUCCESS;
}
