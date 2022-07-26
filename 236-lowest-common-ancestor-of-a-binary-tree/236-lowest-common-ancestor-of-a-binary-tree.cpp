/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //TC-O(nodes)..
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)  return NULL;
        if(root == p or root==q)    return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l!=NULL and r!=NULL) return root;    //if ancestor is root of p and q..
        if(l!=NULL or r!=NULL)  return l != NULL ? l : r;   //if ancestor is either of p and q itself..
        return NULL;
    }
};