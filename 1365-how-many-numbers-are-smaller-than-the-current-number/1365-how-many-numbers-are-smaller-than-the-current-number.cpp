class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr = nums;
        sort(arr.begin(),arr.end());
        vector<int>res;
        for(int i=0;i<n;i++){
           auto it = lower_bound(arr.begin(),arr.end(),nums[i]);
           int cnt = distance(arr.begin(),it);
           res.push_back(cnt);
        }
        return res;
    }
};