class Solution {
public:
    //Reverse Dijsktra(Greatest Path)...BFS, TC-O(n+e)*logn
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dist(n, -1);
        vector<vector<pair<int, double>>> graph(n);
        priority_queue<pair<double, int>> pq;
        for(int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        dist[start] = 1;
        pq.push({1, start});
        while(!pq.empty())
        {
            double d1 = pq.top().first;
            int parent = pq.top().second;
            pq.pop();
            for(auto &j : graph[parent])
            {
                int child = j.first;
                double d2 = j.second;
                if(d1 * d2 > dist[child])
                {
                    dist[child] = d1 * d2;
                    pq.push({dist[child], child});
                }
            }
        }
        
        return dist[end]==-1 ? 0 : dist[end];
    }
};