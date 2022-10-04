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
    //BFS
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)    return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode *node = q.front().first;
                int currSum = q.front().second;
                q.pop();
                
                if(currSum == targetSum and !node->left and !node->right)
                    return true;
                
                if(node->left)  
                    q.push({node->left, currSum + node->left->val});
                if(node->right)
                    q.push({node->right, currSum + node->right->val});
            }
        }
        return false;
    }
};