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
    //BFS, TC-O(nlogn), SC-O(n)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> map;
         //map -> [vertical Index(x) -> {depth or level(y) -> nodes}]
        queue<pair<TreeNode*, pair<int, int>>> q;   
        //q-> [node, {vertical index(x), depth or level(y)}];
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            map[x][y].insert(node->val);
            
            if(node->left) q.push({node->left, {x-1, y+1}});    //left
            if(node->right) q.push({node->right, {x+1, y+1}});  //right
        }
        
        vector<vector<int>> res;
        for(auto &x: map)     //index of vertical column..
        {
            vector<int> v;
            for(auto &y: x.second)      //index of depth or level of tree....
            {
                for(auto &node: y.second)   //all the falling nodes in map[x][y]..
                {
                    v.push_back(node);
                }
            }
            res.push_back(v);
        }
        
        return res;
    }
};