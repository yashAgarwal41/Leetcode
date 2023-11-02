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
    //Tc-O(nodes), SC-O(1)
    int ans = 0;
    pair<int, int> dfs(TreeNode* root)
    {
        if(root == NULL)    return pair<int, int> {0, 0};
        
        pair<int, int> p1 = dfs(root->left);
        pair<int, int> p2 = dfs(root->right);
        int totSum = p1.first + p2.first + root->val;
        int totCnt = p1.second + p2.second + 1;
        int avg = totSum/totCnt;
        if(avg == root->val)    ans++;
        
        return pair<int, int> {totSum, totCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};