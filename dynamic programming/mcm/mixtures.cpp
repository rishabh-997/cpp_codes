/**
https://www.spoj.com/problems/MIXTURES/
*/
 
ll solve(vector<vector<ll> > &color, int n) {
    vector<vector<ll> > dp(n, vector<ll>(n, INT64_MAX));
    int i, j, l;
    for (i = 0; i < n; i++)
        dp[i][i] = 0;
 
    for (l = 2; l <= n; l++) {
        int e = n - l;
        for (i = 0; i <= e; i++) {
            int k = i + l - 1;
            for (j = i; j < k; j++) {
                ll sum = (dp[i][j] + dp[j + 1][k]) + (color[i][j] * color[j + 1][k]);
                ll new_color = (color[i][j] + color[j + 1][k]) % 100;
                if (sum < dp[i][k]) {
                    dp[i][k] = sum;
                    color[i][k] = new_color;
                }
            }
        }
    }
    return dp[0][n - 1];
}
 
int main() {
    //fastRead()
    int n;
    while (cin >> n) {
        vector<vector<ll> > colors(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++)
            cin >> colors[i][i];
        ll ans = solve(colors, n);
        cout << ans << '\n';
    }
    return EXIT_SUCCESS;
} 

