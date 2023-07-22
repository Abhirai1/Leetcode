class Solution {
public:
    
        void  dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>>&vis){
        
        vis[row][col]=1;
        
        int n=grid.size(); 
        int m=grid[0].size();
        
        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,1,-1,0};
        
        for(int i=0;i<4;i++){
            
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&         grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis);
            }
            
        }
        
        
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        
                
        int n=grid.size(); 
        int m=grid[0].size(); 
        
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        int cnt=0;
        
        for(int i=0;i<n;i++){
            
            if(grid[i][0]==1 && !vis[i][0]){
                
                dfs(i,0,grid,vis);
                
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                
                dfs(i,m-1,grid,vis);
                
            }
            
        }
        
        for(int j=0;j<m;j++){
            
            if(grid[0][j]==1 && !vis[0][j]){
                
                dfs(0,j,grid,vis);
                
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                
                dfs(n-1,j,grid,vis);
                
            }
            
        }
        
        cout<<"Visited Matrix :- "<<endl;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};