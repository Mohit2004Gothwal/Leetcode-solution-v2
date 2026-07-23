class Solution {
public: 
    void recursion(int ind , vector<int>& nums, vector<int>& present , vector<vector<int>>&   result ){
        if(ind == nums.size()){
            result.push_back(present);
            return;
        }
        // include current element
        present.push_back(nums[ind]);
        recursion(ind+1 , nums ,present , result);

        // backtrak
        // undo previous choice before
        present.pop_back();

        // skip every duplicate of the curr val
        int pos = ind+1;
        while(pos < nums.size() && nums[pos] == nums[ind]){
            pos++;
        }

        // exclude the current val and all of its duplicates
        recursion(pos , nums , present ,result);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;

    //    sort the array
        sort(nums.begin(),nums.end());
        vector<int>present;
        // recursion
        recursion(0,nums, present,result );
        return result;
    }
};