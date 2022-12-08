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
    void dfs(TreeNode* root, string &s)
    {
        if(root == NULL)    return;
        if(root->left == NULL and root->right == NULL)
        {
            s += (root->val + '0' + '#');
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="", s2="";
        dfs(root1, s1);
        dfs(root2, s2);
        return s1 == s2;
    }
};