class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(auto wd : words){
            int k = wd.size();
            int sum =0;
            for(int i=0;i<k;i++){
              sum += weights[wd[i]-'a'];
              
            }
            sum %=26;
           
             char ch= 'z'-sum;
            res +=  ch;

        }
        return res;
    }
};