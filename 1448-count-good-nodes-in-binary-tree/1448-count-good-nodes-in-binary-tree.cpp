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
    //BFS, TC-O(no of nodes..)
    int goodNodes(TreeNode* root) {
        if(root == NULL)    return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        int ans=0;
        
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int maxi = q.front().second;
            q.pop();
            
            if(node->val >= maxi)   ans++;
            maxi = max(maxi, node->val);
            if(node->left)  q.push({node->left, maxi});
            if(node->right) q.push({node->right, maxi});
        }
        
        return ans;
    }
};