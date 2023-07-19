class Solution {
public:
     void solver(int i,int j,vector<vector<char>> & grid,vector<vector<int>> & visited)
    {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;

        while(!q.empty())
        {
            auto p=q.front();
            int row=p.first;
            int col=p.second;
            q.pop();

            int nr=row+1;
            int nc=col+0;

            if((nr>=0 && nr<n) && (nc>=0 && nc<m) && visited[nr][nc]==0 && grid[nr][nc]=='1')
            {
                visited[nr][nc]=1;
                q.push({nr,nc});

            }

              nr=row;
            nc=col+1;

            if((nr>=0 && nr<n) && (nc>=0 && nc<m) && visited[nr][nc]==0 && grid[nr][nc]=='1')
            {
                visited[nr][nc]=1;
                q.push({nr,nc});

            }

              nr=row-1;
            nc=col;

            if((nr>=0 && nr<n) && (nc>=0 && nc<m) && visited[nr][nc]==0 && grid[nr][nc]=='1')
            {
                visited[nr][nc]=1;
                q.push({nr,nc});

            }
              nr=row;
            nc=col-1;

            if((nr>=0 && nr<n) && (nc>=0 && nc<m) && visited[nr][nc]==0 && grid[nr][nc]=='1')
            {
                visited[nr][nc]=1;
                q.push({nr,nc});

            }




           
                
            }
        }   
       
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0));

        int cnt=0;

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(visited[i][j]==0 && grid[i][j]=='1')
               {
                   solver(i,j,grid,visited);
                   cnt++;
               }
               
           }
       }
       return cnt;
       
    }
//         void  bfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid){
        
//         vis[r][c]=1; 
//         queue<pair<int,int>> q; 
//         q.push({r,c}); 
        
//         int n=grid.size();
//         int m=grid[0].size(); 
        
//         while(!q.empty()){
            
//             int row=q.front().first; 
//             int col=q.front().second; 
//             q.pop(); 
            
//             for(int delrow=-1;delrow<=1;delrow++){
                
//                 for(int delcol=-1;delcol<=1;delcol++){
                    
//                     int nrow=row+delrow; 
//                     int ncol=col+delcol; 
                    
//                     if( nrow>=0 && nrow<n && ncol>=0 && ncol<m                     
//                     && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
//                         vis[nrow][ncol]=1; 
//                         q.push({nrow,ncol});
                        
//                     }
                
//                 }
                
//             }
             
//         }
        
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
        
//         int n=grid.size();
//         int m=grid[0].size(); 
        
        
//         vector<vector<int>> vis(n,vector<int>(m,0));
//         int cnt=0; 
        
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
                
//                 if(!vis[i][j] && grid[i][j]=='1'){
//                      cnt++;
//                     bfs(i,j,vis,grid);
                     
//                 }
                
                
//             }
//         }
          
//         return cnt;
          
//     }
};