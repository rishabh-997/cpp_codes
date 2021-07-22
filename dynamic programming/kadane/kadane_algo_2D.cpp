 int kadane(vector<int> &arr) {
        int sum = 0, ans = INT_MIN;
        for(int i = 0;i<arr.size();i++) {
            sum += arr[i];
            ans = max(ans, sum);
            if(sum<0)
                sum = 0;
        }
        return ans;
    }
    
    int maximumSumRectangle(int n, int m, vector<vector<int>> arr) {
        int ans = INT_MIN;
        vector<int> dp(n);
        for (int i = 0; i < m; i++) {
            dp.assign(dp.size(), 0);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++)
                    dp[k] += arr[k][j];
                ans = max(ans, kadane(dp));
            }
        }
        return ans;
    }
