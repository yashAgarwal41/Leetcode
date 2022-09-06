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
    bool containsOne(TreeNode*root)
    {
        if(root == NULL)    return false;
        
        bool left = containsOne(root->left);
        bool right = containsOne(root->right);
        if(left == false)   root->left = NULL;
        if(right == false)  root->right = NULL;
        if(left == false and right == false and root->val==0)   return false;
        else return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool found = containsOne(root);
        if(!found and root->val==0)    return NULL;
        return root;
    }
};