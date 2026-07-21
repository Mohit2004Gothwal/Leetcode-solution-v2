class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones= 0 , maxsum = 0 , prevsum = -1;
        int i =0;
        while(i<n){
            if(s[i] == '1'){
                ones++;
                i++;
            }else{
                int curr =0;
                while(i<n && s[i] == '0'){
                    curr++;
                    i++;
                }
                if(prevsum > 0){
                    maxsum = max(maxsum , prevsum + curr);
                }
                prevsum = curr;
            }

        }
       return ones+ maxsum;
    }
};