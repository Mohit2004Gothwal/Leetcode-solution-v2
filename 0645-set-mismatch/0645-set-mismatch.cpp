class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
       sort(nums.begin(),nums.end());
       int val = -1,mat = nums[0];
       int val1 = nums[0];
       vector<int>cnt(n+1,0);
       for(int num : nums){
        cnt[num]++;
       }
       for(int i=1;i<=n;i++){
        if(cnt[i] ==0){
            val = i;
            break;
        }
       }
      
       for(int i=1;i<=n;i++){
         if(nums[i] == nums[i-1]){
            val1 = nums[i];
            break;
         }
       }
       
       return {val1,val};
    }
};