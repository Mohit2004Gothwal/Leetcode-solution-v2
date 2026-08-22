#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private: 
    bool checkHorizontal(const vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Calculate total sum, row sums, and frequencies
        long long totalsum = 0;
        vector<long long> rowsum(m, 0);
        vector<unordered_map<int, int>> rowfreq(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = grid[i][j];
                rowsum[i] += val;
                rowfreq[i][val]++;
                totalsum += val;
            }
        }
        
        // Track the top section state
        long long topsum = 0;
        unordered_map<int, int> topfreqs;

        // Track bottom section state
        long long bottomsum = totalsum;
        unordered_map<int, int> bottomfreq;
        for(int i = 0; i < m; i++){
            for(auto pair : rowfreq[i]){
                bottomfreq[pair.first] += pair.second;
            }
        }
        
        // Step 2: Evaluate each horizontal cut 
        for(int i = 0; i < m - 1; i++){
            topsum += rowsum[i];
            bottomsum -= rowsum[i];

            for(auto pair : rowfreq[i]){
                topfreqs[pair.first] += pair.second;
                bottomfreq[pair.first] -= pair.second;
                if(bottomfreq[pair.first] == 0){
                    bottomfreq.erase(pair.first);
                }
            }
            
            // Scenario 1: Sum matched perfectly
            if(topsum == bottomsum) return true;

            // Scenario 2: Top section is heavier
            if(topsum > bottomsum){
                long long targetval = topsum - bottomsum;
                // Note: values can be up to 100000 inclusive
                if(targetval <= 100000 && topfreqs.count(targetval)){
                    int toprows = i + 1;
                    if(toprows > 1 && n > 1) return true;
                    if(toprows == 1){
                        if(grid[0][0] == targetval || grid[0][n - 1] == targetval) return true;
                    }
                    if(n == 1){
                        if(grid[0][0] == targetval || grid[i][0] == targetval) return true;
                    }
                }
            }
            
            // Scenario 3: Bottom section is heavier
            if(bottomsum > topsum){
                long long targetval = bottomsum - topsum;
                if(targetval <= 100000 && bottomfreq.count(targetval)){
                    // Fix 3: Calculation adjusted to find remaining rows
                    int bottomrows = m - (i + 1); 
                    if(bottomrows > 1 && n > 1) return true;
                    if(bottomrows == 1){
                        if(grid[m - 1][0] == targetval || grid[m - 1][n - 1] == targetval) return true;
                    }
                    if(n == 1){
                        if(grid[i + 1][0] == targetval || grid[m - 1][0] == targetval) return true;
                    }
                }
            }
            // Fix 1: Removed 'return false;' from inside the loop
        }
        return false; 
    }
    
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(checkHorizontal(grid)) return true;
        
        int m = grid.size();
        int n = grid[0].size();
        
        // Fix 2: Rectified matrix transposition syntax
        vector<vector<int>> transposed(n, vector<int>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                transposed[j][i] = grid[i][j];
            }
        }
        return checkHorizontal(transposed);
    }
};
