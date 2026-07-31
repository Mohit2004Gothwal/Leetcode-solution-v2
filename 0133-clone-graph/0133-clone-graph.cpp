/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* dfs(Node* node){
        if(!node)return NULL;
        Node* cloned = new Node(node->val);
        mp[node] = cloned;
        
        for(auto nei : node->neighbors){
           if(mp[nei]){
            cloned->neighbors.push_back(mp[nei]);
           }else{
            cloned->neighbors.push_back(dfs(nei));
           }
        }
        return cloned;


    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};