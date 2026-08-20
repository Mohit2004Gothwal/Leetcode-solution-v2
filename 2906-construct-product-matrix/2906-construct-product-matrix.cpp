#define mod 12345

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long prod = 1;
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res[i][j] = prod;
                prod = (prod* (grid[i][j]%mod))%mod;
            }
        }
       
       
        prod =1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i][j] = (res[i][j]*prod)%mod;
                prod =( prod*(grid[i][j]%mod))%mod;

            }
        }
        return res;
    }
};