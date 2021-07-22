//number of ways to make change for N cents, if we have infinite supply of 
//each of coins


    long long int count( int arr[], int m, int n )
    {
       vector<long long int> dp(n+1, 0);
       dp[0] = 1;
       for(long long int i = 0;i<m;i++) {
           for(long long int j = 0;j<=n;j++) {
               if(j<arr[i]) {
                   continue;
               } else {
                   dp[j] += (dp[j-arr[i]]);
               }
           }
       }
       return dp[n];
    }
