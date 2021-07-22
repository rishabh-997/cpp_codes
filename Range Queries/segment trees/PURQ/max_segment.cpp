/**
*	1. we have to find the maximum segment of array
* 	2. so we need 4 values: segment, sum, prefix, suffix
*	3. see merge function for details on how to implement it
*/

struct node {
    int sum, pre, suf, seg;
};

vi arr;
vector<node> segment;
int n;

// element, frequency
node merge(node a, node b) {
    node c{};
    c.sum = a.sum + b.sum;
    c.seg = max(max(a.seg, b.seg), a.suf + b.pre);
    c.pre = max(a.pre, a.sum + b.pre);
    c.suf = max(b.suf, b.sum + a.suf);
    return c;
}

void build_tree(int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        segment[id] = {arr[left], arr[left], arr[left], arr[left]};
        return;
    }
    int mid = (left + right) / 2;
    build_tree(2 * id, left, mid);
    build_tree(2 * id + 1, mid, right);
    segment[id] = merge(segment[2 * id], segment[2 * id + 1]);
}

void update(int pos, int val, int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        segment[id] = {val, val, val, val};
        arr[pos] = val;
        return;
    }
    int mid = (left + right) / 2;
    if (pos < mid)
        update(pos, val, 2 * id, left, mid);
    else
        update(pos, val, 2 * id + 1, mid, right);
    segment[id] = merge(segment[2 * id], segment[2 * id + 1]);
}

node query(int x, int y, int id = 1, int left = 0, int right = n) {
    if (left >= x && right <= y)
        return segment[id];
    if (right <= x || left >= y)
        return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    int mid = (left + right) / 2;
    return merge(query(x, y, 2 * id, left, mid),
                 query(x, y, 2 * id + 1, mid, right));
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int q;
        cin >> n >> q;
        arr.resize(n);
        segment.resize(4 * n + 1);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        build_tree();
        node x = query(0, n);
        if (x.seg < 0)
            cout << "0\n";
        else
            cout << x.seg << "\n";

        while (q--) {
            int a, b;
            cin >> a >> b;
            update(a, b);
            node x = query(0, n);
            if (x.seg < 0)
                cout << "0\n";
            else
                cout << x.seg << "\n";
        }
    }
    return EXIT_SUCCESS;
}
