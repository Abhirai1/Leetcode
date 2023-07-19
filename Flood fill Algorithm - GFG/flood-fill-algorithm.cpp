//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

        void  dfs(int sr,int sc,vector<vector<int>> &ans,vector<vector<int>> &img,int color,int iniColor){
        
        ans[sr][sc]=color;
        
        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,1,-1,0};
        
        int n=img.size(); 
        int m=img[0].size();
        
        for(int i=0;i<4;i++){
            
            int nrow=sr + delrow[i];
            int ncol=sc + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
              img[nrow][ncol]==iniColor && ans[nrow][ncol]!=color)
                dfs(nrow,ncol,ans,img,color,iniColor);
            
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int iniColor=image[sr][sc];
        
        vector<vector<int>> ans=image; 
        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends