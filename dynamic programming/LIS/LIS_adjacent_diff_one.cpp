int longestSubsequence(int n, int arr[])
    {
        vector<int> dp(n);
        for(int i = 0; i<n;i++) {
            dp[i] = 1;
            for(int j = 0;j<i;j++) {
                if(abs(arr[i]-arr[j]) ==1){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ans = 0;
        for(auto x:dp)
            ans = max(x, ans);
        return ans;
    }
