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
int n, maxx = 100003;

void update_segment_tree(int pos, int value, int id = 1, int lx = 0, int rx = maxx) {
    if (rx - lx == 1) {
        segment[id] = value;
        return;
    }
    int mid = (lx + rx) / 2;
    if (pos < mid)
        update_segment_tree(pos, value, id * 2, lx, mid);
    else
        update_segment_tree(pos, value, 2 * id + 1, mid, rx);
    segment[id] = segment[id * 2] + segment[id * 2 + 1];
}

int query_segment_tree(int x, int y, int id = 1, int lx = 0, int rx = maxx) {
    if (lx > rx)
        return 0;
    if (rx <= x || lx >= y)
        return 0;

    if (lx >= x && rx <= y)
        return segment[id];

    int mid = (lx + rx) / 2;
    return query_segment_tree(x, y, 2 * id, lx, mid) +
           query_segment_tree(x, y, 2 * id + 1, mid, rx);
}


int32_t main() {
    fastRead()
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        int value;
        cin >> n;
        arr.resize(maxx);
        segment.resize(4 * maxx);
        segment.assign(segment.size(), 0);
        for (int i = 0; i < n; i++) {
            cin >> value;
            update_segment_tree(value, 1);
            cout << query_segment_tree(value + 1, maxx) << " ";
        }
    }
    return EXIT_SUCCESS;
}



