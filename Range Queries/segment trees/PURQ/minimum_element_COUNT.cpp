/**
*	1. prints the minimum element and its frequency
*	2. we create a MERGE function which will replace all functions
*	3. rest is same as [x, y) format
*/

vi arr;
vpi segment;
int n;

// element, frequency
pi merge(pi a, pi b) {
    if (a.first < b.first)
        return a;
    else if (a.first > b.first)
        return b;
    else
        return {a.first, a.second + b.second};
}

void build_tree(int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        segment[id] = {arr[left], 1};
        return;
    }
    int mid = (left + right) / 2;
    build_tree(2 * id, left, mid);
    build_tree(2 * id + 1, mid, right);
    segment[id] = merge(segment[2 * id], segment[2 * id + 1]);
}

void update(int pos, int val, int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        segment[id] = {val, 1};
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

pi query(int x, int y, int id = 1, int left = 0, int right = n) {
    if (left >= x && right <= y)
        return segment[id];
    if (right <= x || left >= y)
        return {INT64_MAX, 0};
    int mid = (left + right) / 2;
    return merge(query(x, y, 2 * id, left, mid),
               query(x, y, 2 * id + 1, mid, right));
}

