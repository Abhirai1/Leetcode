class Solution {
public:
    
  void fillMatrix( vector<vector<int>> &ans, vector<vector<int>> &grid,queue<pair<pair<int,int>,int>> &q,vector<vector<int>> &vis){
    
    int n=grid.size(); 
	int m=grid[0].size();
	    
    int delrow[4]={-1,0,0,1};
    int delcol[4]={0,1,-1,0};
    
    while(!q.empty()){
            
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            ans[row][col] = dis;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
    }
    
   }
   
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
int n=grid.size(); 
	    int m=grid[0].size();
	    
	    vector<vector<int>> ans(n,vector<int> (m,0));
	    vector<vector<int>> vis(n,vector<int> (m,0));
	   
	    queue<pair<pair<int,int>,int>> q; 
	   
	  for(int i=0;i<n;i++){
	      for(int j=0;j<m;j++){
	          if(grid[i][j]==0){
	              q.push({{i,j},0});
	              vis[i][j]=1;
	          }
	          else{
	              vis[i][j]=0;
	          }
	      }
	  }
	  
	  fillMatrix(ans,grid,q,vis);
	  
	  return ans;
    }
};