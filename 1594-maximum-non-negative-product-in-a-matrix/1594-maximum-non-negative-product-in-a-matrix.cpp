#define mod 1000000007
#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<ll>>maxgt(m,vector<ll>(n));
        vector<vector<ll>>minlt(m,vector<ll>(n));

        maxgt[0][0] = minlt[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            maxgt[0][i] = minlt[0][i] = maxgt[0][i-1]*grid[0][i]; 
        }
        for(int i=1;i<m;i++){
            maxgt[i][0] = minlt[i][0]= maxgt[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]>=0){
                    maxgt[i][j] = max(maxgt[i][j-1] , maxgt[i-1][j])*grid[i][j];
                    minlt[i][j] = min(minlt[i][j-1], minlt[i-1][j])*(grid[i][j]);
                }else{
                    maxgt[i][j] = min(minlt[i][j-1],minlt[i-1][j])*(grid[i][j]);
                    minlt[i][j] = max(maxgt[i][j-1],maxgt[i-1][j])*(grid[i][j]);
                }
            }
        }
        if(maxgt[m-1][n-1]<0)return -1;
        else return maxgt[m-1][n-1]%mod;
 

    }
};