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
    //TC-O(n), SC-O(n)..
    int n;
    unordered_map<int ,int> map;
    
    TreeNode* help(int inL, int inR, int preL, int preR, vector<int> &inorder, vector<int> &preorder)
    {
        if(preL>preR or inL>inR or preL<0 or inL<0 or preR>=n or inR>=n)  return NULL;
        
        TreeNode* root = new TreeNode(preorder[preL]);
        int rootPos = map[preorder[preL]];  //position of root in inorder array..
        int cnt = rootPos-inL;  //no of elements for left traversal in inorder array..
        
        root->left = help(inL, rootPos-1, preL+1, preL + cnt, inorder, preorder);
        root->right = help(rootPos+1, inR, preL + cnt + 1, preR, inorder, preorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        for(int i=0; i<n; i++)  map[inorder[i]] = i;
        
        return help(0, n-1, 0, n-1, inorder, preorder);
        
    }
};