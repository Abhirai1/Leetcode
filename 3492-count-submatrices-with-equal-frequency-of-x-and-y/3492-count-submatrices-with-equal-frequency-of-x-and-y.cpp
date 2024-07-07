class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 

        vector<vector<int>> x(n,vector<int> (m,0));
        vector<vector<int>> y(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(i==0){
                x[i][0]=(grid[i][0]=='X' ? 1 :0);
                y[i][0]=(grid[i][0]=='Y' ? 1 :0);
            }else{
                x[i][0]=(grid[i][0]=='X' ? 1 :0) + x[i-1][0];
                y[i][0]=(grid[i][0]=='Y' ? 1 :0) + y[i-1][0];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(i==0){
                    x[i][j] = x[i][j-1] + (grid[i][j]=='X' ? 1 :0);
                    y[i][j] = y[i][j-1] + (grid[i][j]=='Y' ? 1 :0);
                }else{
                    x[i][j] = x[i-1][j] + x[i][j-1] - x[i-1][j-1] + (grid[i][j]=='X' ? 1 :0);
                    y[i][j] = y[i-1][j] + y[i][j-1] - y[i-1][j-1] + (grid[i][j]=='Y' ? 1 :0);
                }
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(x[i][j]>0 && x[i][j]==y[i][j]) cnt++;
            }   
        }

        return cnt;
    }
};