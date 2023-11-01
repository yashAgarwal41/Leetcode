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
    //TC-O(nodes), SC-O(nodes)
    unordered_map<int, int> mp;
    int maxi = 0;
    
    void traverse(TreeNode* root)
    {
        if(root==NULL)  return;
        
        mp[root->val]++;
        maxi = max(maxi, mp[root->val]);
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        vector<int> ans;
        for(auto it:mp)
        {
            if(it.second == maxi)   ans.push_back(it.first);
        }
        return ans;
    }
};