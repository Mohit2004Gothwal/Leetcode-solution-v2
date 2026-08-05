#define mod 1000000007
class Solution {
public:
    long long modPow(long long base , long long exp){
        long long res =1;
        base%= mod;
        while(exp > 0){
            if(exp%2 !=0) res = (res*base)%mod;
            base = (base*base)%mod;
            exp /=2;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>>adj(n+1);
        vector<bool>vis(n+1,false);
        for(auto it: edges){
               int u = it[0];
               int v = it[1];
               adj[u].push_back(v);
               adj[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        vis[1] = true;
        int d = -1;
        while(!q.empty()){
            int sz =q.size();
            d++;

            for(int i=0;i<sz;i++){
                int curr = q.front();
                q.pop();

                for(auto nei : adj[curr]){
                    if(!vis[nei]){
                        vis[nei] = true;
                        q.push(nei);
                    }
                }

            }
        }
            if(d == 0 )return 0;
            return modPow(2,d-1);
    }
};