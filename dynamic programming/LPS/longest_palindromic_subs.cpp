LPS	

	int n = s.length();
        int dp[n][n];
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && len !=2)
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else if(s[i] == s[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        cout << dp[0][n - 1] << '\n';
