/*
	There is an array of n elements, initially filled with zeros. You need to write a data structure 
	that processes two types of queries:
	1. MAX to the segment from l to r−1 the number v,
	2. find the current value of element i.
*/


vector<int> segment;
int n;

void update(int x, int y, int val, int id = 1, int left = 0, int right = n) {
    if (left >= x && right <= y) {
        segment[id] = max(val, segment[id]);
        return;
    }
    if (left >= y || right <= x)
        return;
    int mid = (left + right) / 2;
    update(x, y, val, 2 * id, left, mid);
    update(x, y, val, 2 * id + 1, mid, right);
}

int query(int pos, int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        return segment[id];
    }
    int ans;
    int mid = (left + right) / 2;
    if (pos < mid)
        ans = query(pos, id * 2, left, mid);
    else
        ans = query(pos, id * 2 + 1, mid, right);
    return max(ans, segment[id]);
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
