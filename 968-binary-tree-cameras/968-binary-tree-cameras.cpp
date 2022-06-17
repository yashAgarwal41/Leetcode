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
    //moving in a postOrder Traversal(Bottom-to-Top)
    //at every node, return a value which will indicate the status of that node..
    // return 0 ->  need camera..
    // return 1 -> covered by camera..
    // return 2 -> have camera..
    int cameras = 0;
    int dfs(TreeNode* root)
    {
        if(root == NULL)    return 1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == 0 or right == 0)
        {
            cameras ++;
            return 2;   //node have set up the camera
        }
        else if(left == 2 or right == 2)
            return 1;   //node is covered by its child(either of child have camera)..
        
        else return 0;  //it is not covered, neither setup the camera..So its parent will set up the camera..
    }
    
    int minCameraCover(TreeNode* root) {
        int rootStatus = dfs(root);
        if(rootStatus == 0) cameras++;
        
        return cameras;
    }
};