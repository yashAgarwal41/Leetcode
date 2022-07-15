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
    unordered_map<int, int> map;
    TreeNode* help(int inL, int inR, int posL, int posR, vector<int> &inorder, vector<int> &postorder)
    {
        if(inL>inR or posL>posR)    return NULL;
        TreeNode* root = new TreeNode(postorder[posR]);
        int rootPos = map[root->val];   //position of root in inorder array..
        int cnt = inR-rootPos;  //no of elements for right traversal in inorder array..
        int leftEndPos = posR-cnt-1;   //dividing position in postorder array..
        
        root->left = help(inL, rootPos-1, posL, leftEndPos, inorder, postorder);
        root->right = help(rootPos+1, inR, leftEndPos+1, posR-1, inorder, postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        for(int i=0; i<n; i++)  map[inorder[i]] = i;
        
        return help(0, n-1, 0, n-1, inorder, postorder);
    }
};