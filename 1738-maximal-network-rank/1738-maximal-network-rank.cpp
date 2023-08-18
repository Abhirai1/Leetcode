class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {


        vector<vector<int>> graph(n,vector<int> (n,0));
        vector<int> ind(n,0);

        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]][roads[i][1]]=1;
            graph[roads[i][1]][roads[i][0]]=1;
            ind[roads[i][0]]++; 
            ind[roads[i][1]]++;
        }
        int ans=INT_MIN;

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
        return ans;
    }
};