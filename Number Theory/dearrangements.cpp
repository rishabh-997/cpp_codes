// returns value of dearrangement
// derr[i] = (i-1) * [derr[i-2] + derr[i-1]]

int countDer(int n) {
    if (n == 1 or n == 2) {
        return n - 1;
    }
    int a = 0, b = 1;
    for (int i = 3; i <= n; ++i) {
        int cur = MUL((i - 1), (a + b));
        a = b;
        b = cur;
    }
    return b % MOD;
}
