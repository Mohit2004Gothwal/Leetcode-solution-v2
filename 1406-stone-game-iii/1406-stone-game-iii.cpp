class Solution {
public:
    int n;
    vector<int>memo;
    int solve(vector<int>& stoneValue , int i){
        if(i>=n)return 0;
        if(memo[i] != -1e9)return memo[i];
        int result =INT_MIN;
        int curr =0;
        for(int x = 0 ;x<3;x++){
           if(i+x<n){
                curr += stoneValue[i+x];
                result = max(result , curr - solve(stoneValue,i+x+1));

            }
        }
        // if(i+1 < n){
        //    result = max(result , stoneValue[i] - solve(stoneValue , i+1));
        // }
        // if(i+2 < n){
        //    result = max(result , stoneValue[i]+stoneValue[i+1] - solve(stoneValue,i+2));
        // }
        // if(i+3 < n){
        //     result = max(result , stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(stoneValue, i+3));
        // }
        return memo[i] = result ;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.assign(n,-1e9);
        int diff = solve(stoneValue,0);
        if(diff >0)return "Alice";
        else if(diff < 0)return "Bob";
        return "Tie";
    }
};