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
    //DFS..TC-O(n^2)..
    int ans = 0;
    void dfs(TreeNode* root, long long target)
    {
        if(root==NULL)  return;
        if(root->val == target)   ans++;
        dfs(root->left, target-root->val);
        dfs(root->right, target-root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root)
        {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};