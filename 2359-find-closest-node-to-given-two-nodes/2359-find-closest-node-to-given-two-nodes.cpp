class Solution {
public:
    vector<int> bfs(vector<int> &graph, int src, int n)
    {
        vector<int> dis(n, INT_MAX);
        queue<int> q;
        dis[src] = 0;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            int it = graph[node];
            if(it==-1)  continue;
            if(dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> graph(n, 0);
        for(int i=0; i<n; i++)
            graph[i] = edges[i];
        
        vector<int> dis1 = bfs(graph, node1, n);
        vector<int> dis2 = bfs(graph, node2, n);
       
        int mini = INT_MAX, ans=-1;
        for(int i=0; i<n; i++)
        {
            int curr = max(dis1[i], dis2[i]);
            if(curr<mini)
            {
                mini = curr;
                ans = i;
            }
        }
        return ans;
    }
};