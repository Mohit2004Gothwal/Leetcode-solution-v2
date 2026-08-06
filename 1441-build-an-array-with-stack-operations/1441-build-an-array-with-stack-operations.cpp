class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr =1;
        vector<string>opr;
        for(int num : target){
            while(curr < num){
                opr.push_back("Push");
                opr.push_back("Pop");
                curr++;
            }
            opr.push_back("Push");
            curr++;
        }
        return opr;
    }
};