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
    int dfs(TreeNode* root, int maxi)
    {
        if(root==NULL)  return 0;
        int ans=0;
        if(root->val >= maxi)   ans++;
        
        maxi = max(maxi, root->val);
        ans += dfs(root->left, maxi);
        ans += dfs(root->right, maxi);
        
        return ans;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        return dfs(root, INT_MIN);
    }
};

