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
    //BFS..
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            double sum=0;
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double avg = sum/n;
            res.push_back(avg);
        }
        return res;
    }
};