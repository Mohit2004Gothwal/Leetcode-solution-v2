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
   pair<int,int>dfs(TreeNode* node){
    if(!node)return {0,0};
    auto [c1 , max1] = dfs(node->left);
    auto [c2 , max2] = dfs(node->right);
    int res = c1 + c2;

    int maxv = max({max1 , max2 , node->val});
    res = c1 + c2 + (maxv == node->val);
    return {res , maxv};
   }
    int countDominantNodes(TreeNode* root) {
        return dfs(root).first;
    }
};