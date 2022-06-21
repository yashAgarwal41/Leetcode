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
    void dfs(TreeNode* root, int target, vector<int> &v, vector<vector<int>> &res)
    {
        if(root==NULL)  return;
        if(root->left==NULL and root->right==NULL)  //leaf Node
        {
            if(target==0)   res.push_back(v);
            return;
        }
        if(root->left)  
        {
            v.push_back(root->left->val);
            dfs(root->left, target-(root->left->val), v, res);
            v.pop_back();   //backtrack
        }
        
        if(root->right) 
        {
            v.push_back(root->right->val);
            dfs(root->right, target-(root->right->val), v, res);
            v.pop_back();   //backtrack
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==NULL)  return res;
        vector<int> v;
        v.push_back(root->val);
        dfs(root, targetSum-root->val, v, res);
        return res;
    }
};