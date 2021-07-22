int countWays(int n, string s){
        int dp[n][n][2];
        memset(dp, 0, sizeof(dp));
        for(int i= 0;i<n;i=i+2) {
            if(s[i]=='T')
                dp[i][i][1] = 1;
            else
                dp[i][i][0] = 1;
        }
        for(int len = 3;len<=n;len=len+2) {
            for(int i = 0;i<n-len+1;i++) {
                int j = i + len - 1;
                int trues = 0, falses = 0;
                for(int k = i + 1; k<j;k=k+2) {
                    int left_true = dp[i][k-1][1], left_false = dp[i][k-1][0];
                    int right_true = dp[k+1][j][1], right_false = dp[k+1][j][0];
                    
                    if(s[k]=='|') {
                        falses += left_false*right_false;
                        trues += (left_true*right_false)
                                    +(left_false*right_true) 
                                        +(left_true*right_true);
                    } else if(s[k]=='&') {
                        trues += left_true*right_true;
                        falses += (left_true*right_false)
                                    +(left_false*right_true) 
                                        +(left_false*right_false);
                    } else {
                        trues += (left_true*right_false) + (left_false*right_true);
                        falses += (left_false*right_false) + (left_true*right_true); 
                    }
                }
                trues = trues%mod;
                falses = falses%mod;
                dp[i][j][1] = trues;
                dp[i][j][0] = falses;
            }
        }
        return dp[0][n-1][1];
    }
