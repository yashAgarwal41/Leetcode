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
    //PreOrder Traversal for every node..
    //TC-O(n^2)..
    bool containsOne(TreeNode *root)
    {
        if(root==NULL)  return 0;
        bool left = containsOne(root->left);
        bool right = containsOne(root->right);
        
        if(left==0 and right==0 and root->val==0)
            return 0;
        
        return 1;
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        if(!containsOne(root))
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
};