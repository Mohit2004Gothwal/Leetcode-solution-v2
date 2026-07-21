class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int currlen = 0 , prevnum = -1, maxlen = 0;
        bool first = true;
        for(auto& [key , val] : mp){
            if(first){
                currlen = 1;
                first = false;
            }else if(key == prevnum+1){
                currlen++;
            }else{
                maxlen = max(maxlen , currlen);
                currlen = 1;
            }
            prevnum = key;
        } 
       return max(maxlen , currlen);
    }
};