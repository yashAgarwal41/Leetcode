class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size(), maxi=0;
        
        //insert adjacent nodes in a graph..
        //it should contain 3 Most scorer adjacent nodes
        vector<set<pair<int, int>>> graph(n);
        for(auto &v:edges)
        {
            graph[v[0]].insert({scores[v[1]], v[1]});
            graph[v[1]].insert({scores[v[0]], v[0]});
            if(graph[v[0]].size()>3)    graph[v[0]].erase(graph[v[0]].begin());
            if(graph[v[1]].size()>3)    graph[v[1]].erase(graph[v[1]].begin());
        }
        
        //now for a sequence of len=4, select 2 middle nodes, i.e 'b' and 'c'..
        //and the other remaining 2 nodes('a','d') will be the adjacent nodes of 'b', 'c'..
        //now check for atmost 3 adjacent nodes of b and c and remove repeated values..
        for(auto &v:edges) //TC-O(edges.size())
        {
            int b = v[0], c = v[1];
            int sz1 = graph[b].size(), sz2 = graph[c].size();
            int score = scores[b] + scores[c];
            
            for(auto &p : graph[b]) //TC-O(3)
            {
                for(auto &q : graph[c]) //TC-(3)
                {
                    int a = p.second, d = q.second;
                    if(a==d or a==b or a==c or d==b or d==c)  continue; //remove repeated
                    maxi = max(maxi, score + scores[a] + scores[d]);
                }
            }
        }
        return maxi == 0 ? -1 : maxi;
    }
};
