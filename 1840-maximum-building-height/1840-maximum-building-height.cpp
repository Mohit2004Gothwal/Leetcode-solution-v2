class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        // push boundary condition to simplify tracking
        res.push_back({1,0});
        res.push_back({n,n-1});

        // sort
        sort(res.begin(),res.end());

        int m = res.size();

        // pass1 : left to right
        for(int i=1;i<m;i++){
            int dis = res[i][0] - res[i-1][0];
            res[i][1] = min(res[i][1] ,res[i-1][1]+dis);
        }

        // pass2 : right to left
        for(int i = m-2;i>=0;i--){
             int dist = res[i+1][0]- res[i][0];
             res[i][1] = min(res[i][1] , res[i+1][1]+dist);
        }

        // pass3 : find abs max peak btw two restriction
        int maxi =0;
        for(int i=0;i<m-1;i++){
            int ind1 = res[i][0],h1 = res[i][1];
            int ind2 = res[i+1][0],h2= res[i+1][1];

            // formula to find the peak element
            int peak =(h1 + h2 + (ind2-ind1))/2;
            maxi = max(maxi , peak);
        }
        return maxi;
    }
};