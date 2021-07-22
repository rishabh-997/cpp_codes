int f(vector<vector<int> > &dp, string &s, int i, int j) {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
                return dp[i][j];
        if(i==j)
                return dp[i][j] = 1;
        if(s[i]==s[j]) {
            return dp[i][j] = 2 + f(dp, s, i+1, j-1); 
        } else {
            return dp[i][j] = max(f(dp, s, i+1, j), f(dp, s, i, j-1)); 
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> > dp (n, vector<int> (n, -1));
        int ans = f(dp, s, 0, n-1);
        return ans;
    }
