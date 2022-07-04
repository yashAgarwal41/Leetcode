class Solution {
public:
    //Reverse Dijsktra(Greatest Path)...BFS, TC-O(n+e)
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<set<pair<int, double>>> graph(n);
        int m = edges.size();
        for(int i=0; i<m; i++)
        {
            graph[edges[i][0]].insert({edges[i][1], succProb[i]});
            graph[edges[i][1]].insert({edges[i][0], succProb[i]});
        }
        
        vector<double> dis(n, -1);  //initial distance as -1
        priority_queue<pair<double, int>> pq;   //MaxHeap
        pq.push({-1, start});   //starting with start point with distance as -1
        
        while(!pq.empty())
        {
            double parentDis = pq.top().first;  //parent distance from start node
            int parentNode = pq.top().second;   //parent node
            pq.pop();
            for(auto &j:graph[parentNode])
            {
                int childNode = j.first;    //childNode..
                double childDis = j.second; //childDistance from parentNode..
                
                double newDis = abs(parentDis*childDis);    //newDistance from start to end..
                if(newDis>dis[childNode])   //if newDistance is greater than prev, then update it and push into queue..
                {
                    pq.push({newDis, childNode});
                    dis[childNode] = newDis;
                }
            }
        }
        
        return dis[end] == -1 ? 0 : dis[end];
    }
};