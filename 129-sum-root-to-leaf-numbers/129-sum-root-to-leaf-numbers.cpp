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
    //DFS..
    int res = 0;
    void dfs(TreeNode* root, string s)
    {
        if(root==NULL)  return;
        if(!root->left and !root->right)    //Leaf Node
        {
            string temp = s + to_string(root->val);
            res += stoi(temp);
            return;
        }
        dfs(root->left, s + to_string(root->val));
        dfs(root->right, s + to_string(root->val));
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};