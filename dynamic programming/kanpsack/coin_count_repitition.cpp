#include <bits/stdc++.h>
 
using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
 
typedef long long ll;
const ll MOD = 1e9 + 7;
 
ll MUL(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
 
ll ADD(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
 
ll SUB(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
 
int main() {
    fastRead()
    ll t;
    //cin >> t;
    t = 1;
    while (t--) {
        ll n, x, a;
        cin >> n >> x;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> a;
            coins[i] = a;
        }
        sort(coins.begin(), coins.end());
        vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= x; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] = (dp[i][j] % MOD + dp[i][j - coins[i - 1]] % MOD) % MOD;
            }
        }
        cout << dp[n][x];
    }
    return EXIT_SUCCESS;
}
