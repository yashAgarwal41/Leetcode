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
    //BFS- Level Order Traversal
    //Take last element of each level..
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front(); 
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==n-1)  res.push_back(node->val);
            }
        }
        return res;
        
    }
};