/*
There is an array of n elements, initially filled with zeros. You need to write a data structure 
that processes two types of queries:
1. add to the segment from l to r−1 the number v,
2. find the current value of element i.
*/

vi arr, segment;
int n;

void build_segment_tree(int id = 1, int left = 0, int right = n) {
    segment.assign(segment.size(), 0);
}

void update_segment_tree(int x, int y, int value, int id = 1, int left = 0, int right = n) {
    // jamai bahar
    if (left >= y || right <= x)
        return;
    // jamai andar
    if (left >= x && right <= y) {
        segment[id] += value;
        return;
    }
    // jamai beech mein
    int mid = (left + right) / 2;
    update_segment_tree(x, y, value, 2 * id, left, mid);
    update_segment_tree(x, y, value, 2 * id + 1, mid, right);
}

int query_segment_tree(int pos, int id = 1, int lx = 0, int rx = n) {
    if (rx - lx == 1) {
        return segment[id];
    }
    int mid = (lx + rx) / 2, ans;
    if (pos < mid)
        ans = query_segment_tree(pos, 2 * id, lx, mid);
    else
        ans = query_segment_tree(pos, 2 * id + 1, mid, rx);
    return ans + segment[id];
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
        build_segment_tree();
        for (int i = 0; i < query; i++) {
            cin >> type;
            if (type == 1) {
                int l, r, v;
                cin >> l >> r >> v;
                update_segment_tree(l, r, v);
            } else {
                int pos;
                cin >> pos;
                cout << query_segment_tree(pos) << "\n";
            }
        }
    }
    return EXIT_SUCCESS;
}


