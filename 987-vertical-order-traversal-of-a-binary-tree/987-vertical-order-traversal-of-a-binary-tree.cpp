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
    //DFS, TC-O(n*logn), SC-O(n)
    map<int, map<int, multiset<int>>> map; //map -> [x -> {y-> nodes}]
    void dfs(TreeNode* root, int index, int depth)
    {
        map[index][depth].insert(root->val);
        
        if(root->left)  dfs(root->left, index-1, depth+1); //left
        if(root->right) dfs(root->right, index+1, depth+1); //right
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        
        for(auto &x:map)    //index of vertical answer..
        {
            vector<int> v;
            for(auto &y:x.second)   //depth index(level in tree)..
            {
                for(auto &node:y.second)
                    v.push_back(node);
            }
            res.push_back(v);
        }
        return res;
    }
};