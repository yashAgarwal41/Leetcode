/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int,set<int>> &graph)
    {
        if(root==NULL)  return;
        
        if(root->left)
        {
            graph[root->val].insert(root->left->val);
            graph[root->left->val].insert(root->val);
        }
        if(root->right)
        {
            graph[root->val].insert(root->right->val);
            graph[root->right->val].insert(root->val);
        }
        dfs(root->left, graph);
        dfs(root->right, graph);
    }
    
     void bfs(int start, int k, vector<int> &dis, unordered_map<int,set<int>> &graph)
    {
        vector<int> vis(501, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        dis[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto j:graph[node])
            {
                if(!vis[j])
                {
                    vis[j] = 1;
                    dis[j] = dis[node]+1;
                    q.push(j);
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,set<int>> graph;
        dfs(root, graph);   //call DFS..
        vector<int> res, dis(501, -1);
        
        bfs(target->val, k, dis, graph);    //call BFS..
        
        for(int i=0; i<501; i++)
        {
            if(dis[i] == k) res.push_back(i);
        }
        return res;
    }
};