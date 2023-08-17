class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<pair<int,double>> adj[n]; 
        int i=0;
        for(auto &it:edges){
            adj[it[0]].push_back({(it[1]),succProb[i]});
            adj[it[1]].push_back({(it[0]),succProb[i]});
            i++;
        }
        vector<double> dis(n,0); 
        // for(int i=0;i<n;i++){
        //     dis[i]=1.0*(INT_MIN);
        // } 
        
        dis[start_node]=1;
        
        priority_queue<pair<int,double>,vector<pair<int,double>>,greater<pair<int,double>>> pq;
        
        pq.push({start_node,1}); 
        
        while(!pq.empty()){
            int node=pq.top().first; 
            double d=pq.top().second; 
            pq.pop();
            
            for(auto &t:adj[node]){
                if(d*t.second>dis[t.first]){
                    dis[t.first]=(d*t.second); 
                    pq.push({t.first,dis[t.first]});
                }
            }
        }
        return dis[end_node];

    }
};