a = first sring
b = second sring

        int dp[a.length() + 1][b.length() + 1];
        for (int i = 0; i <= b.length(); i++)
            dp[0][i] = i;
        for (int i = 0; i <= a.length(); i++)
            dp[i][0] = i;
        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        cout << dp[a.length()][b.length()] << '\n';

