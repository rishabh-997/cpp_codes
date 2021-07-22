/**
*	Shortest common subsequence
*	n = s1, m = s2 sizes
*	ans = n+m-lcs(s1, s2)
*	print dekh lo kese kara
*/


	string shortestCommonSupersequence(string a, string b) {
        int n = a.length(), m = b.length();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                if(a[i-1]==b[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans;
        int i = n, j = m;
        while(i>0 && j>0) {
            if(a[i-1]==b[j-1]) {
                ans.push_back(a[i-1]);
                i--, j--;
            } else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    ans.push_back(a[i-1]);
                    i--;
                } else {
                    ans.push_back(b[j-1]);
                    j--;
                }
            }
        }
        if(i>0) {
            ans.push_back(a[i-1]);
            i--;
        }
        if(j>0) {
            ans.push_back(b[j-1]);
            j--;
        }


        reverse(ans.begin(), ans.end());
        return ans;
    }
