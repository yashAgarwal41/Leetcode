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
    int ans=0;
    
    bool isPal(unordered_map<int, int> &map)
    {
        int odd=0;
        for(auto it:map)
        {
            if(it.second%2) odd++;
            if(odd>1)   return false;
        }
        return true;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int> &map)
    {
        if(root==NULL)  return;
        if(root->left==NULL and root->right == NULL)
        {
            map[root->val]++;
            if(isPal(map))    ans++;
            map[root->val]--;
            return;
        }
        map[root->val]++;
        dfs(root->left, map);
        dfs(root->right, map);
        map[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> map;
        dfs(root, map);
        return ans;
    }
};