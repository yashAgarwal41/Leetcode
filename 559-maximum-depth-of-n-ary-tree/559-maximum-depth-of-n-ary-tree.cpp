/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* root)
    {
        if(root==NULL)  return 0;
        int maxi=0;
        for(int i=0; i<root->children.size(); i++)
        {
            int temp = dfs(root->children[i]);
            maxi =max(maxi, temp);
        }
        return 1 + maxi;
    }
    int maxDepth(Node* root) {
        if(root == NULL)    return 0;
        return dfs(root);
    }
};