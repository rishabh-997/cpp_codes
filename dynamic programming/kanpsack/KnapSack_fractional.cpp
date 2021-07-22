int knapSack(int n, int w, int val[], int wt[]) {
        int dp[w+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=w;j++) {
                if(wt[i-1]>j)
                    continue;
                else
                    dp[j] = max(dp[j], val[i-1] + dp[j-wt[i-1]]);
            }
        }
        return dp[w];
    }
