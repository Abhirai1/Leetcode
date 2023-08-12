class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V=graph.size();
         
       vector<int> adjRev[V]; 
       vector<int> ind(V,0);
       
       for(int i=0;i<V;i++){
           for(int j=0;j<graph[i].size();j++){
               adjRev[graph[i][j]].push_back(i);
               ind[i]++;
           }
       }
       
       queue<int> q; 
       
       for(int i=0;i<V;i++){
           if(ind[i]==0){
               q.push(i);
           }
       }
       
       vector<int> ans;
       while(!q.empty()){
           
           int node = q.front(); 
           ans.push_back(node); 
           q.pop(); 
           
           for(auto &it:adjRev[node]){
               ind[it]--; 
               
               if(ind[it]==0){
                   q.push(it);
               }
           }
       }
       
       sort(ans.begin(),ans.end());
       
       return ans;   
        
    }
};