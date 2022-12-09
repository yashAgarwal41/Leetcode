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
    void dfs(TreeNode* root, int maxi, int mini, int &ans)
    {
        if(root == NULL)    return;
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        ans = max(ans, abs(maxi-mini));
        dfs(root->left, maxi, mini, ans);
        dfs(root->right, maxi, mini, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN, maxi = INT_MIN, mini = INT_MAX;
        dfs(root, maxi, mini, ans);
        return ans;
    }
};