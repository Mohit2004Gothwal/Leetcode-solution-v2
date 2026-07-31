class Solution {
public:
   int helper(int r , int c , vector<vector<char>>& matrix , vector<vector<int>>& cache){
    int n = matrix.size();
    int m = matrix[0].size();

    if(r >= n && c >= m) return 0;
      return 1;
   }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int size = 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(matrix.empty())return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i || !j || matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j]-'0';
                }else{
                    dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]))+1;
                }
                size = max(dp[i][j] , size);
            }
        }
         return size*size;
    }
};