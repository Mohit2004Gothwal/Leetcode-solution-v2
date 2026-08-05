class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int ans =0,k=0;
      for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans = max(ans,k);
                k=0;
            } else{
               k++;
            }
      }
      ans = max(ans , k);
      return ans;
    }
};