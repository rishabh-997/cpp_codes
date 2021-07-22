/**
* nCr calculator using inverse property, but for n,r >= 1e18
* factorial = stores factorial
* inverse   = calculates inverse in array in O(M) time
*/
	int MOD = 999983;
	vi factorial, inverse;

	int MUL(int a, int b) {
	    return ((a % MOD) * (b % MOD)) % MOD;
	}

	void pre_compute() {
	    factorial.resize(MOD + 5);
	    inverse.resize(MOD + 5);
	    factorial.assign(factorial.size(), 1);
	    inverse.assign(inverse.size(), 1);
	    for (int i = 2; i < factorial.size(); i++)
		factorial[i] = MUL(i, factorial[i - 1]);
	    inverse[1] = 1;
	    for (int i = 2; i < inverse.size(); i++)
		inverse[i] = (((-inverse[MOD % i] * (MOD / i)) % MOD) + MOD) % MOD;
	}

	// Use directly in case of small integers
	int nCr_digits(int n, int r) {
	    if (r == 0 || r == n)
		return 1;
	    if (r > n)
		return 0;
	    if (n < 0)
		return 0;
	    int ans = factorial[n];
    	    ans = MUL(ans, inverse[factorial[n - r]]);
            ans = MUL(ans, inverse[factorial[r]]);
	    return ans;
	}

	int nCr(int n, int r) {
	    if (r == 0 || r == n)
		return 1;
	    if (r > n)
		return 0;
	    if (n < 0)
		return 0;
	    int n1 = n % MOD;
	    int r1 = r % MOD;
	    return MUL(nCr_digits(n1, r1), nCr(n / MOD, r / MOD));
	}
