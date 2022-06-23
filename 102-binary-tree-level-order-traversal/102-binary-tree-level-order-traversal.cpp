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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)    return res;      
        queue<TreeNode*> q; //this queue will contain the nodes at each level..
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();   //number of nodes on each level..
            vector<int> level;  
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)  q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            res.push_back(level);
        }
        return res;
    }
};