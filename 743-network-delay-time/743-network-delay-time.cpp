#define pr pair<int, int>
class Solution {
public:
    //Dijkstra's Algo, BFS, TC-O(n+e)logn
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pr>> graph(n+1);
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for(auto &v : times)
        {
            graph[v[0]].push_back({v[1], v[2]});
        }
        
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            int parDis = pq.top().first;
            int parNode = pq.top().second;
            pq.pop();
            
            for(auto &j : graph[parNode])
            {
                int chDis = j.second;
                int chNode = j.first;
                if(parDis + chDis < dist[chNode])
                {
                    dist[chNode] = parDis + chDis;
                    pq.push({dist[chNode], chNode});
                }
            }
        }
        
        
        int maxi = *max_element(dist.begin()+1, dist.end());
        return maxi == INT_MAX ? -1 : maxi;
    }
};