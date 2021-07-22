/**
*	1. Nested segments are those segment which completely lie inside segment
*	2. x y z y z x : x has 2 segs
*	3. we keep track of starting and ending index of an element and as soon as it ends.
*	4. we count the number of ones in that segment
*	5. ONE is assigned at poition of initial value of element which indicates that it has completed
*/

vi segment;
int n;

void update(int pos, int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        segment[id] = 1;
        return;
    }
    int mid = (left + right) / 2;
    if (mid > pos)
        update(pos, id * 2, left, mid);
    else
        update(pos, id * 2 + 1, mid, right);
    segment[id] = segment[id * 2] + segment[id * 2 + 1];
}

int query(int x, int y, int id = 1, int left = 0, int right = n) {
    if (left >= x && right <= y)
        return segment[id];
    if (right <= x || left >= y)
        return 0;
    int mid = (left + right) / 2;
    return query(x, y, id * 2, left, mid)
           + query(x, y, id * 2 + 1, mid, right);
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int a;
        cin >> n;
        vvi arr(n+1);
        vi ans(n);
        n = 2 * n;
        segment.resize(4 * n + 1);
        segment.assign(segment.size(), 0);
        for (int i = 0; i < n; i++) {
            cin >> a;
            arr[a].push_back(i);
            if (arr[a].size() == 2) {
                int x = arr[a][0], y = arr[a][1];
                int temp = query(x, y + 1);
                ans[a - 1] = temp;
                update(x);
            }
        }
        for (auto x: ans)
            cout << x << " ";
    }
    return EXIT_SUCCESS;
}

