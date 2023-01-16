class Solution {
public:
    #define P pair<long long,long long> 
    long long mod = 1e9 + 7;
    int dijkstra(vector<pair<int, int>> adj[], int n) {

        priority_queue<P, vector<P>, greater<P>> pq;
        
        vector<long long>distance(n, 1e15), path(n, 0);
        distance[0] = 0;
        pq.push({0, 0});
        path[0] = 1;

        while(!pq.empty()){
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edgeW = it.second;
                
                if(dist + edgeW < distance[adjNode]){
                    distance[adjNode] = dist + edgeW;
                    path[adjNode] = path[node];
                    pq.push({distance[adjNode], adjNode});
                }else if(dist + edgeW == distance[adjNode]){
                    
                    path[adjNode] = (1LL*path[node] + 1LL*path[adjNode]) % mod;
                }
            }
        }
        return path[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n];

        // Graph Creation
        for (auto &v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        return dijkstra(adj, n);
    }
};