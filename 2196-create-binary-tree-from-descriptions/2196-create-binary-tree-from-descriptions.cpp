/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& description) {
        unordered_map<int,TreeNode*>nodemap;
        unordered_set<int>children;

        for(auto desc : description){
            int par = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            if(nodemap.find(par) ==nodemap.end()){
                nodemap[par] = new TreeNode(par);
            }

             if(nodemap.find(child) ==nodemap.end()){
                nodemap[child] = new TreeNode(child);
            }

            // Link parent to child
            if(isLeft){
                nodemap[par]->left = nodemap[child];
            }else{
                nodemap[par]->right = nodemap[child];
            }
            children.insert(child);
        }
        for(auto desc : description){
            int par = desc[0];
            if(children.find(par) == children.end()){
                return nodemap[par];
            }
        }
        return NULL;
    }
};