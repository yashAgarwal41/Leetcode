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
    int mini = 1000, maxi = 1000, maxDepth=0;
    void dfs(TreeNode* root, int index, int depth, vector<vector<multiset<int>>> &ans)
    {
        mini = min(mini, index);
        maxi = max(maxi, index);
        maxDepth = max(maxDepth, depth);
        ans[index][depth].insert(root->val);
        
        if(root->left)  dfs(root->left, index-1, depth+1, ans);
        if(root->right) dfs(root->right, index+1, depth+1, ans);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<multiset<int>>> ans(2005, vector<multiset<int>> (1005));
        dfs(root, 1000, 0, ans);
        vector<vector<int>> res;
        
        for(int i=mini; i<=maxi; i++)
        {
            vector<int> v;
            for(int j=0; j<=maxDepth; j++)
            {
                if(ans[i][j].size()==0) continue;
                for(auto &k:ans[i][j])
                {
                    v.push_back(k);
                }
            }
            // for(auto j : ans[i])
            // {
            //     v.push_back(j);
            // }
            res.push_back(v);
        }
        return res;
    }
};