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
    void preOrder(Node* root, vector<int> &res)
    {
        if(root==NULL)  return;
        
        res.push_back(root->val);   //root
        
        int n = (root->children).size();
        for(int i=0; i<n; i++)
            preOrder(root->children[i], res);   //all children
        
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};