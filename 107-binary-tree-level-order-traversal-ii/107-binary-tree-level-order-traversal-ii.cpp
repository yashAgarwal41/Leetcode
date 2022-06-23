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
    //Without reversing the answer..
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)  return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+max(lh, rh);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
        {
            vector<vector<int>> res;
            return res;
        }
        
        int n = maxDepth(root); //no of levels in the tree..
        vector<vector<int>> res(n);
        queue<TreeNode*> q;
        q.push(root);
            
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res[n-1] = level;
            n--;
        }
        return res;
    }
};