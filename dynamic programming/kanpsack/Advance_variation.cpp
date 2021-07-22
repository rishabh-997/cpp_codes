/**
* Susbset Sum advance variations
* Find all possible sum formed using susbet
* Min difference subset in them
* sum = sum / 2 will give if it can be divided in two
*/	


int minDiffernce(int arr[], int n) { 
	int sum = 0;
        for(int i = 0;i<n;i++)
            sum = sum + arr[i];
        bool dp[n+1][sum+1];
        memset(dp, false, sizeof(dp));
        for(int i = 0;i<=n;i++) 
            dp[i][0] = true;
        sort(arr, arr+n);
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=sum;j++) {
                if(arr[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        int ans = 0;
        for(int j = sum/2;j>=0;j--) {
            if(dp[n][j]) {
                ans = sum - 2*j;
                break;
            }
        }
        return ans;
}
