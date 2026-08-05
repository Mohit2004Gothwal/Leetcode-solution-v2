class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // adjancy list
        vector<vector<int>>adj(n);
        for(auto edge:invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        // find the suspicious methods
        vector<bool>issuspicious(n,false);
        queue<int>q;

        q.push(k);
        issuspicious[k] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int nei : adj[curr]){
                if(!issuspicious[nei]){
                    q.push(nei);
                    issuspicious[nei] = true;
                }
            }
        }
        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];
            if(!issuspicious[u] && issuspicious[v]){
                // external dependency found , unsafe to remove anything
                vector<int>allmethods(n);
                iota(allmethods.begin(),allmethods.end(),0);
                return allmethods;

            }
        }
        vector<int>rem;
        for(int i=0;i<n;i++){
            if(!issuspicious[i]){
                rem.push_back(i);
            }
        }
        return rem;
    }
};