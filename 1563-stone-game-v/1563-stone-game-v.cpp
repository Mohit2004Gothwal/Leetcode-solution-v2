class Solution {
public:
//    vector<vector<int>>memo(501,vector<int>(501,-1));
    int memo[501][501];
    int solve(int l , int r , vector<int>& prefix){
        if(l>=r)return 0;
        if(memo[l][r]!= -1)return memo[l][r];
        int score =0;
        for(int mid = l;mid<=r-1;mid++){
            int leftsum =0;
            if(l-1>=0){
                leftsum =prefix[mid]-prefix[l-1];

            }else{
                leftsum = prefix[mid];
            }
            int rightsum = prefix[r]-prefix[mid];

            if(leftsum < rightsum ){
                score = max(score , leftsum + solve(l,mid,prefix));
            }else if(leftsum > rightsum){
                score = max(score , rightsum + solve(mid+1 , r,prefix));
            }else{
                score = max({score , leftsum + solve(l,mid,prefix),rightsum + solve(mid+1,r,prefix)});
            }
        }
        return memo[l][r]=score;

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>prefix(n,0);
        memset(memo,-1,sizeof(memo));
        prefix[0] = stoneValue[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+stoneValue[i];
        }
        return solve(0,n-1,prefix);
    }
};