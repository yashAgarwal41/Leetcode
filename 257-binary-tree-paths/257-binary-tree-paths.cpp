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
    void dfs(TreeNode* root, string s, vector<string> &res)
    {
        if(root==NULL)  return;
        if(root->left==NULL and root->right==NULL)
        { 
            res.push_back(s + to_string(root->val));
            return;
        }
        
        dfs(root->left, s + to_string(root->val) + "->", res);
        dfs(root->right, s + to_string(root->val) + "->", res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        
        return res;
    }
};