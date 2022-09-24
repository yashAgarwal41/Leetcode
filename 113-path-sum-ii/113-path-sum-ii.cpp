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
    void dfs(TreeNode* root, int sum, int target, vector<int> &path, vector<vector<int>> &res)
    {

        sum += root->val;
        path.push_back(root->val);
        if(root->left == NULL and root->right == NULL)
        {
            if(sum == target)   res.push_back(path);
            sum -= root->val;
            path.pop_back();
            return;
        }
        
        if(root->left)  dfs(root->left, sum, target, path, res);
        if(root->right) dfs(root->right, sum, target, path, res);
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        if(root == NULL)    return res;
        vector<int> path;
        dfs(root, 0, target, path, res);
        return res;
        
    }
};