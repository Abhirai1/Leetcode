class Solution {
public:
        int cntmin(vector<pair<int,int>> adj[],priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> &pq,vector<long long> &dis,int n){
        
        vector<long long> comingPath(n,0);
        
       int mod=(1e9+7); 
        
        pq.push({0,0}); 
        comingPath[0]=1;
        dis[0]=0;
        
        
        while(!pq.empty()){
            
            long d=pq.top().first;
            int node=pq.top().second; 
            pq.pop(); 
            
            for(auto &it:adj[node]){
                
                int u=it.first; 
                long wt=it.second; 
                
                if(d+wt<dis[u]){
                    dis[u]=d+wt; 
                    pq.push({d+wt,u});
                    comingPath[u]=comingPath[node];
                }
                else if(d+wt==dis[u]){
                    comingPath[u]=(comingPath[u]+comingPath[node])%mod;
                }
                
            }
        }
        
        return int(comingPath[n-1]%mod);
    }
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<long long> dis(n,1e18); 
        dis[0]=0;
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> pq;
        
        vector<pair<int,int>> adj[n]; 
        
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        } 
        
        return  cntmin(adj,pq,dis,n);
    }
};