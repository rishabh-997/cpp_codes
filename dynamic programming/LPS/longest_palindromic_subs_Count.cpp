int f(vector<vector<ll> > &dp, string &s, int start, int end) {
        if(start>end)   
            return 0;
        if(start==end)
            return dp[start][end]=1;
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        if(s[start]==s[end]) {
            if(start+1==end)
                return dp[start][end]=3;
            else {
                ll ans = 1 + f(dp, s, start+1, end) + f(dp,s,start, end-1);
                return dp[start][end] = ans%mod;
            }
        } else {
            ll a = f(dp, s, start+1, end) + f(dp,s,start, end-1);
            ll b = f(dp, s, start+1, end-1);
            a = SUB(a, b);
            return dp[start][end] = a%mod;
        }
    }
    
    ll countPS(string s) {
        int n = s.length();
        vector<vector<ll> > dp(n, vector<ll> (n, -1));
        f(dp, s, 0, n-1);
        return dp[0][n-1];
    }
