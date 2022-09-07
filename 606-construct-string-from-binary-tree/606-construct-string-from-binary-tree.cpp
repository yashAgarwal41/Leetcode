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
    string ans = "";
    void dfs(TreeNode* root)
    {
        if(root == NULL)    return;
        ans += "(";
        ans += to_string(root->val);
            
        if(root->left and root->right)
        {
            dfs(root->left);
            dfs(root->right);
        }
        else if(root->left and !root->right)
        {
            dfs(root->left);
            // ans += "()";
        }
        else if(!root->left and root->right) 
        {
            ans += "()";
            dfs(root->right);
        }
        ans += ")";
    }   
    string tree2str(TreeNode* root) {
        dfs(root);
        ans.pop_back();
        ans = ans.substr(1);
        return ans;
    }
};