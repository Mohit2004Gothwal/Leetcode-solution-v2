class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total =0;
        bool allzero = true;
        for(int x : nums){
            total ^= x;
            if(x >0)allzero = false;
        }
        if(total > 0 )return n;
        return allzero ? 0 :n-1;
    }
};