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
        vector<int> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *node;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                node = q.front(); 
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==n-1)  res.push_back(node->val);
            }
        }
        return res;
        
    }
};