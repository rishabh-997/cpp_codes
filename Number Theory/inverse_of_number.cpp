/**
*	Calculates inverse of a mod m;
*	call "inverse(x, mod - 2) % MOD"
*  	works if a, m are co-prime
*/

ll inverse(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2)
            ans = MUL(ans, a);
        a = MUL(a, a);
        b = b / 2;
    }
    return ans % MOD;
}
