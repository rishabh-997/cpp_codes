class Solution {
public:
    int maxi = INT32_MAX - 10;
    
    int backtrack(vector<int> &coins, int amount, vector<int> &dp, vector<bool> &ready) {
        if (amount < 0)
            return maxi;
        if (amount == 0)
            return 0;
        if (ready[amount])
            return dp[amount];
        int ans = maxi;
        for (int x : coins) {
            ans = min(ans, backtrack(coins, amount - x, dp, ready) + 1);
        }
        dp[amount] = ans;
        ready[amount] = true;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        vector<bool> ready(amount + 1, false);
        int ans = backtrack(coins, amount, dp, ready);
        if (ans == maxi)
            return -1;
        return ans;
    }
};
