class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> cost(n,vector<int> (n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    cost[i][j]=0;
                }
                else{
                    cost[i][j]=1e9;
                }
            }
        }

        for(auto it:edges){
            cost[it[0]][it[1]]=it[2]; 
            cost[it[1]][it[0]]=it[2];
        } 

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
        }

        int bari=INT_MAX;
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
               if(cost[i][j]<=distanceThreshold)
               cnt++;
            }
            if(cnt<=bari){
                ans=max(ans,i);
                bari=cnt;
            }
        }

        return ans;
    }
};