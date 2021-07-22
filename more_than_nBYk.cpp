// numbers that occur more than n/k times

int countOccurence(int arr[], int n, int k) {
        vector<pair<int,int> > dp(k-1, {0,0});
        for(int i = 0;i<n;i++) {
            int x = arr[i];
            bool flag = false;
            for(int i = 0;i<k-1;i++) {
                if(dp[i].first==x) {
                    dp[i].second += 1;
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            flag = false;
            for(int i = 0;i<k-1;i++) {
                if(dp[i].second==0) {
                    dp[i].second = 1;
                    flag = true;
                    dp[i].first = x;
                    break;
                }
            }
            if(flag)
                continue;
            for(int i = 0;i<k-1;i++)
                dp[i].second -= 1;
        }
        for(int i=  0;i<k-1;i++) {
            int cunt = 0;
            int x = dp[i].first;
            for(int j = 0;j<n;j++) {
                if(arr[j]==x)
                    cunt++;
            }
            if(cunt>(n/k))
                return x;
        }
        return -1;
    }
