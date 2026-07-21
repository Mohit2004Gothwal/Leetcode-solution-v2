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
    unordered_map<int,int>inordermap;
    int postind;
    TreeNode* helper(vector<int>&postorder , int inst , int inend){
        if(inst > inend)return NULL;
        // pick current root from postorder
        int rootval = postorder[postind--];
        TreeNode* root = new TreeNode(rootval);

        // get root index from inorder
        int rootinind = inordermap[rootval];

        // build the right subtree
        root->right =helper(postorder , rootinind + 1 , inend);
        root->left = helper(postorder , inst , rootinind-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postind = postorder.size()-1;

        // map to the corresponding index
        for(int i=0;i<inorder.size();i++){
            inordermap[inorder[i]] = i;
        }
        return helper(postorder , 0, inorder.size()-1);
    }
};