class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt= 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>cols(m);
        for(int i=0;i<n;i++){
            int rows =0 ;
            for(int j=0;j<m;j++){
              cols[j] += grid[i][j];
              rows += cols[j];
              if(rows <= k)cnt++;
            }
        }
        return cnt;
    }
};