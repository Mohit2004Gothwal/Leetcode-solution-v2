class Solution {
public:
    int func(int ind, vector<int>& prices, int buy, vector<vector<int>>& dp) {
        int n = prices.size();
        if (ind == n)
            return 0; // base case
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + func(ind + 1, prices, 0, dp),
                         func(ind + 1, prices, 1, dp));

        } else {
            profit = max(prices[ind] + func(ind + 1, prices, 1, dp),
                         func(ind + 1, prices, 0, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + dp[ind+1][0],
                                dp[ind+1][1]);

                } else {
                    profit = max(prices[ind] + dp[ind+1][1],
                                 dp[ind+1][0]);
                }
                 dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
        // return func(0, prices, 1, dp);
    }
};