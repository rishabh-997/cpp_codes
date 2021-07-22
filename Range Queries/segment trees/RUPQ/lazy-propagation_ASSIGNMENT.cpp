/*
There is an array of n elements, initially filled with zeros. You need to write a data 
structure that processes two types of queries:
1. assign value v to all elements on the segment from l to r−1,
2. find the current value of element i.
*/

vector<int> segment;
int n;

int operation(int node_value, int value) {
    // Assign value to node
    // if value is NOT ASSIGNED, then dont update the node
    if (value == -1)
        return node_value;
    return value;
}

void propagate(int id, int left, int right) {
    // Leaf Child
    if (right == left + 1)
        return;
    segment[id * 2] = operation(segment[2 * id], segment[id]);
    segment[id * 2 + 1] = operation(segment[2 * id + 1], segment[id]);
    // wapas khali kardo node ko after propogation
    segment[id] = -1;
}

void update(int x, int y, int val, int id = 1, int left = 0, int right = n) {
    propagate(id, left, right);
    if (left >= x && right <= y) {
        segment[id] = operation(segment[id], val);
        return;
    }
    if (left >= y || right <= x)
        return;
    int mid = (left + right) / 2;
    update(x, y, val, 2 * id, left, mid);
    update(x, y, val, 2 * id + 1, mid, right);
}

int query(int pos, int id = 1, int left = 0, int right = n) {
    propagate(id, left, right);
    if (left + 1 == right) {
        return segment[id];
    }
    int ans;
    int mid = (left + right) / 2;
    if (pos < mid)
        ans = query(pos, id * 2, left, mid);
    else
        ans = query(pos, id * 2 + 1, mid, right);
    return ans;
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int q;
        cin >> n >> q;
        segment.resize(4 * n + 1);
        segment.assign(segment.size(), 0);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r, v;
                cin >> l >> r >> v;
                update(l, r, v);
            } else {
                int i;
                cin >> i;
                cout << query(i) << "\n";
            }
        }
    }
    return EXIT_SUCCESS;
}



