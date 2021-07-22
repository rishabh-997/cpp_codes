int nth_fibo(int b) {
    ll a[2][2] = {{1, 1},
                  {1, 0}};
    ll ans[2][2] = {{1, 0},
                    {0, 1}};
    ll c[2][2];
    while (b != 0) {
        if (b % 2 == 1) {
            c[0][0] = (ans[0][0] % MOD * a[0][0] % MOD) + (ans[0][1] % MOD * a[1][0] % MOD);
            c[0][1] = (ans[0][0] % MOD * a[0][1] % MOD) + (ans[0][1] % MOD * a[1][1] % MOD);
            c[1][0] = (ans[1][0] % MOD * a[0][0] % MOD) + (ans[1][1] % MOD * a[1][0] % MOD);
            c[1][1] = (ans[1][0] % MOD * a[0][1] % MOD) + (ans[1][1] % MOD * a[1][1] % MOD);
            ans[0][0] = c[0][0] % MOD, ans[0][1] = c[0][1] % MOD;
            ans[1][0] = c[1][0] % MOD, ans[1][1] = c[1][1] % MOD;
        }
        b = b / 2;
        c[0][0] = (a[0][0] % MOD * a[0][0] % MOD) + (a[0][1] % MOD * a[1][0] % MOD);
        c[0][1] = (a[0][0] % MOD * a[0][1] % MOD) + (a[0][1] % MOD * a[1][1] % MOD);
        c[1][0] = (a[1][0] % MOD * a[0][0] % MOD) + (a[1][1] % MOD * a[1][0] % MOD);
        c[1][1] = (a[1][0] % MOD * a[0][1] % MOD) + (a[1][1] % MOD * a[1][1] % MOD);
        a[0][0] = c[0][0] % MOD, a[0][1] = c[0][1] % MOD;
        a[1][0] = c[1][0] % MOD, a[1][1] = c[1][1] % MOD;
    }
    return (ans[1][0] % MOD);
}
