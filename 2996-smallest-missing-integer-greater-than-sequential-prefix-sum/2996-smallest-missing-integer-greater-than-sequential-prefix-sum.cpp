class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        vector<bool>freq(1276,0);
        freq[nums[0]] =1;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                sum += nums[i];
                freq[nums[i]] =1;
            }else{
                while(i < n){
                    freq[nums[i]]=1;
                    i++;
                }
            }
        }
        int ans;
        for(int i = sum;i <1277;i++){
            if(freq[i] == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};