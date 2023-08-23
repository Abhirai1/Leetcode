class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n=image.size();
        int m=image[0].size();

        int tcolor=image[sr][sc];

        image[sr][sc]=color;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,1,-1,0};
        
        while(!q.empty()){

            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){

                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==tcolor && image[nrow][ncol] !=image[row][col]){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }

            }
        }

        return image;
        
    }
};