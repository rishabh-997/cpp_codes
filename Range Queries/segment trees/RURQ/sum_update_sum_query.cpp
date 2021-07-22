// we cant use it normally because it is not distributive
// ie, (a+x) + (b+x) = (a+b) + 2x instead of (a+b) + x

int ADD(int a, int b) {
    // return (a % MOD + b % MOD) % MOD;
    return a + b;
}

int MUL(int a, int b, int len) {
    //return ((a % MOD) * (b % MOD)) % MOD;
    return a + (b * len);
}

// minimum array, operation array
vi values, segment;
int n;

void build_segment_tree(int id = 1, int left = 0, int right = n) {

}

void update_segment_tree(int x, int y, int value, int id = 1, int left = 0, int right = n) {
    // jamai outside
    if (left >= y || right <= x)
        return;
    // jamai inside
    if (left >= x && right <= y) {
        segment[id] = MUL(segment[id], value, 1);
        values[id] = MUL(values[id], value, right - left);
        return;
    }
    // jamai beech mein
    int mid = (left + right) / 2;
    update_segment_tree(x, y, value, 2 * id, left, mid);
    update_segment_tree(x, y, value, 2 * id + 1, mid, right);
    values[id] = MUL(ADD(values[id * 2], values[id * 2 + 1]), segment[id], right - left);
}

int query_segment_tree(int x, int y, int id = 1, int left = 0, int right = n) {
    // jamai outside
    if (left >= y || right <= x)
        return 0;
    // jamai inside
    if (left >= x && right <= y) {
        return values[id];
    }
    // jamai beech mein
    int mid = (left + right) / 2;
    int l = query_segment_tree(x, y, 2 * id, left, mid);
    int r = query_segment_tree(x, y, 2 * id + 1, mid, right);
    return MUL(ADD(l, r), segment[id], min(y, right) - max(left, x));
}

