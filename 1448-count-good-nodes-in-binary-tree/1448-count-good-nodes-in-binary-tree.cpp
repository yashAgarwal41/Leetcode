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
    void dfs(TreeNode* root, int maxi, int &ans)
    {
        if(root == NULL)    return;
        
        if(root->left)
        {
            if(root->left->val >= maxi) ans++;
            dfs(root->left, max(maxi, root->left->val), ans);
        }
        if(root->right)
        {
            if(root->right->val >= maxi)    ans++;
            dfs(root->right, max(maxi, root->right->val), ans);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        int ans=1;
        dfs(root, root->val, ans);
        return ans;
    }
};

