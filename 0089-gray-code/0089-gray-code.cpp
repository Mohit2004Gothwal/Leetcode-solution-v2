class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>val;
        int total = 1<<n;
        for(int i=0;i<total ; i++){
            val.push_back(i^(i>>1));
        }
        return val;
    }
};