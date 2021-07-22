/**
* Segment Tree to find and update sum values in a range
	pattern is [init, final)
*/


arr.resize(n);
segment.resize(4 * n + 1);

void build_segment_tree(int id = 1, int left = 0, int right = n) {
    if (right - left == 1) {
        // leaf node hai
        segment[id] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    // left sub-tree
    build_segment_tree(id * 2, left, mid);
    // right sub-tree
    build_segment_tree(id * 2 + 1, mid, right);
    segment[id] = segment[id * 2] + segment[id * 2 + 1];
 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_segment_tree(int pos, int value, int id = 1, int lx = 0, int rx = n) {
    if (rx - lx == 1) {
        arr[pos] = value;
        segment[id] = value;
        return;
    }
    int mid = (lx + rx) / 2;
    // left side par hai
    if (pos < mid)
        update_segment_tree(pos, value, id * 2, lx, mid);
    else
        update_segment_tree(pos, value, 2 * id + 1, mid, rx);
    segment[id] = segment[2 * id] + segment[2 * id + 1];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// (starting index, ending index, id of node, start of node, end of node)
// [x, y)
int query_segment_tree(int x, int y, int id = 1, int lx = 0, int rx = n) {
    // [lx, ry) lies entirely outside [x, y)
    if (rx <= x || lx >= y)
        return 0;

    // [lx, ry) lies entirely inside [x, y)
    if (lx >= x && rx <= y)
        return segment[id];

    // [lx, ry) lies partially inside [x, y)
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
        int query, type, a, b;
        cin >> n >> query;
        arr.resize(n);
        segment.resize(4 * n + 1);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        build_segment_tree();
        while (query--) {
            cin >> type >> a >> b;
            if (type == 1)
                update_segment_tree(a, b);
            else
                cout << query_segment_tree(a, b) << "\n";
        }
    }
    return EXIT_SUCCESS;
}


