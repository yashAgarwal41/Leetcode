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
    //BFS, TC-O(n), SC-O(n)
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)    return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                int m = node->children.size();  //no of children nodes of parent node..
                for(int j=0; j<m; j++)
                {
                    q.push(node->children[j]);  //push all children in queue..
                }
            }
            
            res.push_back(level);
        }
        
        return res;
    }
};