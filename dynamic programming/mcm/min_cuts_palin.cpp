	int minCut(string s) {
        int n = s.length();
        vector<vector<bool> > palin(n, vector<bool> (n, false));
        
        for(int i =0;i<n;i++){
            palin[i][i] = true;
        }

        // standard mcm
        for(int l = 2;l<=n;l++) {
            for(int i = 0;i<n-l+1;i++) {
                int j = i + l - 1;
                if(l==2)
                    palin[i][j] = s[i]==s[j];
                else
                    palin[i][j] = (s[i]==s[j])&&palin[i+1][j-1];
            }
        }

	// evaluation
        vector<int> dp(n);
        for(int i = 0;i<n;i++) {
            if(palin[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = INT_MAX;
                for(int j = 0;j<i;j++) {
                    if(palin[j+1][i]) {
                        dp[i] = min(dp[i], 1 + dp[j]);
                    }
                }
            }
        }
        
        return dp[n-1];
    }

