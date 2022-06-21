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
    int dfs(TreeNode* root, string s)
    {
        if(root==NULL)  return 0;
        if(!root->left and !root->right)    //Leaf Node
        {
            string temp = s + to_string(root->val);
            return stoi(temp);
        }
        int left = dfs(root->left, s + to_string(root->val));
        int right = dfs(root->right, s + to_string(root->val));
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, "");
    }
};