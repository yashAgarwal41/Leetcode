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
    bool dfs(TreeNode* root, int uniValue)
    {
        if(root == NULL)    return true;
        if(root->val != uniValue) return false;
        
        bool left = dfs(root->left, uniValue);
        bool right = dfs(root->right, uniValue);
        
        return left and right;
    }
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};