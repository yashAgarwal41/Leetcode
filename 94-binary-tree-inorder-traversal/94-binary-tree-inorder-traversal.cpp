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
    void help(TreeNode* node, vector<int> &res)
    {
        if(node==NULL)  return;
        
        help(node->left, res);      //left
        res.push_back(node->val);   //root
        help(node->right, res);     //right
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, res);
        return res;
    }
};