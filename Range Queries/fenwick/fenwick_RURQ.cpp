/*
	1. we use zero BIT array
	2. update bit[a] with val
	3. update bit[b+1] with -val
 	4. query ans is arr[k] + query(k)

*/

void update(vi &bit, int pos, int n, int val) {
    while (pos <= n) {
        bit[pos] += val;
        pos = pos + (pos & (-pos));
    }
}

int query(vi &bit, int n, int a) {
    int ans = 0;
    while (a > 0) {
        ans = ans + bit[a];
        a = a & (a - 1);
    }
    return ans;
}

int32_t main() {
    fastRead()
    int tests = 1;
    //cin >> tests >> ws;
    for (int t = 1; t <= tests; t++) {
        int n, q;
        cin >> n >> q;
        vi arr(n + 1), bit(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int a, b, u;
                cin >> a >> b >> u;
                update(bit, a, n, u);
                update(bit, b + 1, n, -1 * u);
            } else {
                int k;
                cin >> k;
                cout << arr[k] + query(bit, n, k) << "\n";
            }
        }
    }
    return EXIT_SUCCESS;
}


