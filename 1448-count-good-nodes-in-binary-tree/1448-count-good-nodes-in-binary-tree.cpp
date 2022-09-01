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
        if(root == NULL)    return 0;
        
        int ans=0;
        if(root->left)
        {
            if(root->left->val >= maxi) ans++;
            ans += dfs(root->left, max(maxi, root->left->val));
        }
        if(root->right)
        {
            if(root->right->val >= maxi)    ans++;
            ans += dfs(root->right, max(maxi, root->right->val));
        }
        return ans;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        return 1 + dfs(root, root->val);    //1 is for the root node..
    }
};

