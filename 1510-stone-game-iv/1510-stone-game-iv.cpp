class Solution {
public:
   vector<int>memo;
   bool dfs(int i){
    if(i==0)return false;
    if(memo[i] != -1)return memo[i];
    for(int j=1;j*j<=i;j++){
        if(!(dfs(i-j*j)))return memo[i] = true;
    }
    return memo[i] = false;
   }
    bool winnerSquareGame(int n) {
        memo.assign(n+1,-1);
        return dfs(n);
    }
};