n = size of array "a"
m = size of array "b"

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }


        int i = n, j = m, index = 0;
        vector<int> ans(dp[n][m], 0);
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                ans[index++] = a[i - 1];
                i--, j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
