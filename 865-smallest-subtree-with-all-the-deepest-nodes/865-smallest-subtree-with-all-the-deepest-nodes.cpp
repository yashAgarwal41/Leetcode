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
    //DFS
    int maxi = 0;
    int dfs(TreeNode* root, TreeNode* &ans, int depth)
    {
        maxi = max(maxi, depth);
        if(root == NULL)    return depth;   
        int left = dfs(root->left, ans, depth+1);    //depth of left subtree
        int right = dfs(root->right, ans, depth+1);  //depth of right subtree
        
        if(left == maxi and right == maxi)  ans = root; //balanced subtree with maxDepth..
        
        return max(left, right);    //return maxDepth
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = root;
        dfs(root, ans, 0);
        return ans;
    }
};