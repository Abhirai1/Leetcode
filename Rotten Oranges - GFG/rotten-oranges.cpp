//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
        void   bfs(vector<vector<int>> &grid,int &cnt,queue<pair<int,int>>& q){
        
        int d1[] = {0,0,1,-1};
        int d2[] = {-1,1,0,0};
        
        int n=grid.size(); 
        int m=grid[0].size();
        
        while(!q.empty()){ 
            int si = q.size();
            cnt++;
              for(int z =0;z<si;z++){
                auto a = q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int row = a.first+d1[k];
                    int col = a.second+d2[k];
                    if(row>=0 && row<n && col>=0 && col<m){
                        if(grid[row][col]==1){
                            grid[row][col] = 2;
                            q.push({row,col});
                        }
                    }
                }
            }
}
    }

        
    
    int orangesRotting(vector<vector<int>>& grid) {    
        
         int n=grid.size(); 
        int m=grid[0].size();
        
   
        queue<pair<int,int>>q; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                
                if(grid[i][j]==2){
                    
                    q.push({i,j});
                    
                }
                
            }
            
        }
        if(q.size()==0){
            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return 0;
        }
        int cnt=0;
        bfs(grid,cnt,q);
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return cnt-1;
               
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends