class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        // vector<int> adj[n]; 
        vector<vector<int>> graph(n,vector<int> (n,0));
        vector<int> ind(n,0);
        // vector<pair<int,int>> connect;
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]][roads[i][1]]=1;
            graph[roads[i][1]][roads[i][0]]=1;
            // adj[it[0]].push_back(it[1]);
            // adj[it[1]].push_back(it[0]);
            ind[roads[i][0]]++; 
            ind[roads[i][1]]++;
        }

        // vector<pair<int,int>> t; 
        // for(int i=0;i<n;i++){
        //     t.push_back({ind[i],i});
        // } 
        // sort(t.begin(),t.end());
        int ans=INT_MIN;
        // for(int i=1;i<0;i++){
        //     if
        // }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(graph[i][j]){
                    ans=max(ans,ind[i]+ind[j]-1);
                }
                else{
                    ans=max(ans,ind[i]+ind[j]);
                }
            }
        }

        // int ans=INT_MIN;
        // vector<int> t;
        // for(int node=0;node<n;node++){
        //     for(auto &it:adj[node]){
        //         // t.push_back(ind[it]+ind[node]-1)
        //         ans=max(ans,(ind[it]+ind[node]-1)); 
        //     }
        // }
        return ans;
    }
};