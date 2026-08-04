class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty())return {};
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>res;
        unordered_set<int>ele(nums.begin(),nums.end());
        for(int i = mini;i<=maxi;i++){
            if(ele.find(i) == ele.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};