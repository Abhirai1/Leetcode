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