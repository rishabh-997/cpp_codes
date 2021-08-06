/**
* Segment Tree to find and update minimum values in a range
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
    segment[id] = min(segment[id * 2], segment[id * 2 + 1]);
}

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
    segment[id] = min(segment[2 * id], segment[2 * id + 1]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// (starting index, ending index, id of node, start of node, end of node)
// [x, y)
int query_segment_tree(int x, int y, int id = 1, int lx = 0, int rx = n) {
    // [x,y) lies entirely outside [lx, ry)
    if (rx <= x || lx >= y)
        return INT64_MAX;

    // [x,y) lies entirely inside [lx, ry)
    if (lx >= x && rx <= y)
        return segment[id];

    // [x,y) lies partially inside [lx, ry)
    int mid = (lx + rx) / 2;
    return min(query_segment_tree(x, y, 2 * id, lx, mid),
               query_segment_tree(x, y, 2 * id + 1, mid, rx));
}


