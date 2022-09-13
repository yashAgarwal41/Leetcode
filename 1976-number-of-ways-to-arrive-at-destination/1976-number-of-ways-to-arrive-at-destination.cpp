#define ll long long
class Solution {
public:
    //Dijkstra's Algo BFS + DP..TC-O(n+Elog(n))..
    /** Use DP to keep states of shortest time fo a node.
    while finding shortest time
    - when we find a shorter time we change dp by new value.
    - when we find equal time we add value to current node's dp.  **/
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> dp(n, 0);
        vector<ll> dis(n, LONG_MAX);
        vector<vector<pair<int, int>>> graph(n);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; //Min-Heap
        
        for(auto &v:roads)
        {
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }
        
        dp[0] = 1;  // initilize it to 1 since to reach 0 we have 1 way
        dis[0] = 0;
        pq.push({0, 0});
        
        while(!pq.empty())
        {
            ll parDis = pq.top().first;
            ll parNode = pq.top().second;
            pq.pop();
            
            for(auto &j : graph[parNode])
            {
                ll chNode = j.first;
                ll chDis = j.second;
                if(chDis > dis[chNode])   continue;   //not necessary
                if(parDis + chDis == dis[chNode])
                {
                    dp[chNode] = (dp[chNode] + dp[parNode])%mod;
                }
                if(parDis + chDis < dis[chNode])
                {
                    dp[chNode] = dp[parNode]%mod;
                    dis[chNode] = parDis + chDis;
                    pq.push({dis[chNode], chNode});
                }
            }
        }
        return dp[n-1];
    }
};