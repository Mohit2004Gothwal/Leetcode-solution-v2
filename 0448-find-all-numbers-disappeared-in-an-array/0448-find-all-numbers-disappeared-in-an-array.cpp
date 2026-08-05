class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        int n = nums.size();
        vector<int>cnt(n+1,0);
        for(int num:nums){
            cnt[num]++;
        }
        for(int i=1;i<=n;i++){
          if(cnt[i] ==0){
            res.push_back(i);
          }
        }
        return res;
    }
};