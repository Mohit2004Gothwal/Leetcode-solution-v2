class Solution {
public:
    int minOperations(string s) {
        int cnt01 =0;
        int n = s.size();
        char ch = s[0];
        for(int i=0;i<s.size();i++){
            // 01
          if(i%2 == 0){
            if(s[i]%2 != '0'){
                if(s[i] != '0')cnt01++;
            }
          }else{
            if(s[i] != '1')cnt01++;
          }
        }
        return min(cnt01 , n - cnt01);
    }
};