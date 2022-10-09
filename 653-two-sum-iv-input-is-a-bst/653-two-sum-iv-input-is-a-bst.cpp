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
    unordered_set<int> set;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)    return false;
        if(set.find(k - root->val) != set.end())   return true;
        set.insert(root->val);
        
        bool left = findTarget(root->left, k);
        bool right = findTarget(root->right, k);
        return left or right;
    }
};