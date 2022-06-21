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
    //DFS
    bool dfs(TreeNode* root, int target)
    {
        if(root==NULL)  return false;
        if(!root->left and !root->right)    //leaf node
            return target == 0;
        bool left=0, right=0;
        if(root->left)
            left = dfs(root->left, target-root->left->val);
        if(root->right)
            right = dfs(root->right, target-root->right->val);
        
        return left or right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)  return false;
        return dfs(root, targetSum-root->val);
    }
};