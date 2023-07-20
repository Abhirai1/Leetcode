//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // bool ptaKroCycle(int source,vector<int> adj[],int vis[]){
    //     vis[source]=1;
    //     queue<pair<int,int>> q; 
    //     q.push({source,-1}); 
        
    //     while(!q.empty()){
            
    //         int node = q.front().first; 
    //         int parent = q.front().second;
    //         q.pop();
            
    //         for(auto &it:adj[node]){
    //             if(!vis[it])
    //             {
    //                 vis[it]++; 
    //                 q.push({it,node});
    //             }
    //             else if(parent != it){
    //                 return true;
    //             }
    //         }
            
    //     }
    //     return false;
    // }
    
    
    bool dfs(vector<int> adj[],int vis[],int source,int parent){
        
        vis[source]=1; 
        
        for(auto &it:adj[source]){
            
            if(vis[it]==0){
                if(dfs(adj,vis,it,source)==true)
                return true;
            }
            else if(it!=parent)
            return true;
        }
        
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        
        // part of dfs
        
        int vis[n]={0};
       for(int i=0;i<n;i++){
           if(!vis[i]){
               if(dfs(adj,vis,i,-1)==true)
               return true;
           }
       } 
      
        return false;
        
        // part of bfs
      
    //     int vis[n]={0}; 
       
    //   for(int i=0;i<n;i++){
           
           
    //       if(!vis[i]){
    //           if(ptaKroCycle(i,adj,vis)==true)
    //           return true;
    //       }
           
           
    //   }
       
    //   return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends