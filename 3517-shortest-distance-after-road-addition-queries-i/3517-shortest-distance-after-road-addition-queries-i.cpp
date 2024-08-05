class Solution {
public:
    int dijkastra(vector<pair<int,int>> adj[], int s,int des){
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        vector<int> dis(des+1,INT_MAX);
        pq.push({0,0}); dis[0]=0;

        while(!pq.empty()){
            auto it=pq.top(); pq.pop();

            int u=it.first; int d=it.second; 

            if(u==des) return d;

            for(auto it:adj[u]){
                int v=it.first;
                int w=it.second;

                // u -------- v  

                if(d+w < dis[v]){
                    dis[v]=d+w; 
                    pq.push({v,dis[v]});
                }
            }
        }

        return des;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans; 
        vector<pair<int,int>> adj[n]; 

        for(int i=0;i<n-1;i++) adj[i].push_back({i+1,1});

        for(auto it:queries){
            adj[it[0]].push_back({it[1],1});

            int dis = dijkastra(adj,0,n-1); 

            ans.push_back(dis);
        }

        return ans;
    }
};