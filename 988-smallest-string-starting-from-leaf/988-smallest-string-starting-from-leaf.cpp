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
    //DFS...
    string ans = "~";
    void dfs(TreeNode* root, string s)
    {
        if(root==NULL)  return;
        if(!root->left and !root->right)    //leafNode
        {
            s = char(root->val + 'a') + s;
            ans = min(ans, s);
        }
        dfs(root->left, char(root->val+'a') + s);
        dfs(root->right, char(root->val+'a') + s);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};