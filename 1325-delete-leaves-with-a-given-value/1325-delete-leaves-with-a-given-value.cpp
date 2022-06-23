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
    //POST ORDER..
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL)    return NULL;
        if(root->left)
            root->left = removeLeafNodes(root->left, target);
        if(root->right)
            root->right = removeLeafNodes(root->right, target);
        if(root->left==NULL and root->right==NULL and root->val==target)
            return NULL;
        
        return root;
    }
};