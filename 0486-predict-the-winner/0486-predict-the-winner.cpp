class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2 == 0 )return true;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i] = nums[i];
        }
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j = i+l;
                dp[i] = max(nums[i] - dp[i+1], nums[j] - dp[i]);
            }
        }
        return dp[0]>=0;
    }
};