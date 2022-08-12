/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : va2l(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //TC-O(height of the tree)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int cur = root->val;
        if(cur < p->val and cur < q->val)   //if both are on the right..
            return lowestCommonAncestor(root->right, p, q);
        if(cur > p->val and cur > q->val)   //if both are on the left..
            return lowestCommonAncestor(root->left, p, q);
        
        return root;    //if one is left and other is right..
    }
};