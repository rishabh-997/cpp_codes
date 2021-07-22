/**
* Given two strings S1 and S2, find the number of times  
* the second string occurs in the first string,
* whether continuous or discontinuous.
* geeksforgeeks, gks
* gives 4
*/



    int f(vector<vector<int> > &dp, string &a, string &b, int i, int j) {
        if(j==b.length())
            return 1;
        if(i>=a.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(a[i]==b[j]) {
            return dp[i][j] = f(dp,a,b,i+1,j+1) + f(dp,a,b,i+1,j);
        } else {
            return dp[i][j] = f(dp,a,b,i+1,j);
        }
    }

    int countWays(string a, string b){
        int n = a.length(), m = b.length();
        vector<vector<int> > dp(n, vector<int> (m , -1));
        return f(dp, a, b, 0, 0);
    }
