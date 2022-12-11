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
//At any root node, maximum path sum from that root = root->val + max sum from left node + max sum from right node..
    int maxi = INT_MIN;
    int maxHeight(TreeNode* root)
    {
        if(root==NULL)  return 0;
        int lh = max(0, maxHeight(root->left)); 
        int rh = max(0, maxHeight(root->right));
        
        maxi = max(maxi, root->val + lh + rh);  //maximum path sum till now
        return root->val + max(lh, rh);     
    }
    int maxPathSum(TreeNode* root) {
        int maxRootSum = maxHeight(root);   //maximum sum with root root node..
        return maxi; 
    }
};