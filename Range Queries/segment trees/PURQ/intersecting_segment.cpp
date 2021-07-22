/**
*	1. Intersecting segments are those segment which partially lie inside segment
*	2. x y z y z x :y, z has 1 segs
*	3. we keep track of starting and ending index of an element and as soon as it ends.
*	4. we count the number of ones in that segment
*	5. ONE is assigned at poition of initial value and after ending is found, starting index in made 0
* 	6. Do once for reverse, once for normal, add both answers
*/

vi segment;
int n;

void update(int pos, int val, int id = 1, int left = 0, int right = n) {
    if (left + 1 == right) {
        segment[id] = val;
        return;
    }
    int mid = (left + right) / 2;
    if (mid > pos)
        update(pos, val, id * 2, left, mid);
    else
        update(pos, val, id * 2 + 1, mid, right);
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
        int a, size;
        cin >> n;
        size = n;
        n = 2 * n;
        vvi arr(size + 1);
        vi ans(size, 0);
        vi array(n);
        segment.resize(4 * n + 1);
        segment.assign(segment.size(), 0);
        // FOR ORIGINAL ORDER
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            a = array[i];
            arr[a].push_back(i);
            if (arr[a].size() == 2) {
                int x = arr[a][0], y = arr[a][1];
                update(x, 0);
                int temp = query(x, y + 1);
                ans[a - 1] += temp;
            } else {
                update(i, 1);
            }
        }

        // FOR REVERSE ORDER
        segment.clear();
        segment.resize(4 * n + 1);
        segment.assign(segment.size(), 0);
        arr.clear();
        arr.resize(n + 1);
        reverse(array.begin(), array.end());
        for(int i = 0;i<n;i++) {
            a = array[i];
            arr[a].push_back(i);
            if (arr[a].size() == 2) {
                int x = arr[a][0], y = arr[a][1];
                update(x, 0);
                int temp = query(x, y + 1);
                ans[a - 1] += temp;
            } else {
                update(i, 1);
            }
        }
        for (auto x: ans)
            cout << x << " ";
    }
    return EXIT_SUCCESS;
}
