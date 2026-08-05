class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(auto wd : words){
            int k = wd.size();
            int sum =0;
            for(int i=0;i<k;i++){
              int ind = weights[wd[i]-'a'];
              sum += ind;
            }
            sum %=26;
            sum = 25-sum;
             char ch= 'a' + sum;
            res +=  ch;

        }
        return res;
    }
};