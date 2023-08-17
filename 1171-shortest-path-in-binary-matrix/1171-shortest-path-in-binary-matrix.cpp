class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
                int n=grid.size(); 

        if(grid[0][0]==1){
            return -1;
        }

        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        vector<vector<int>> dis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis[i][j]=1e9;
            }
        } 
        
        priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>> , greater<pair<pair<int,int>,int>> > pq;
        
        if(grid[0][0]==0)
        pq.push({{0,0},0});
        dis[0][0]=0;
        
        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,1,-1,0};
        
        while(!pq.empty()){
            
            int row=pq.top().first.first;
            int col=pq.top().first.second;
            int d=pq.top().second;
            pq.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow = row + i;
                    int ncol = col + j;
                
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                        if(d+1<dis[nrow][ncol]){
                            dis[nrow][ncol]=d+1;
                            pq.push({{nrow,ncol},d+1});
                        }
                    }
                }
            }
        }
        if(dis[n-1][m-1]==1e9)
        return -1;
        
        return dis[n-1][m-1]+1;
    }
};