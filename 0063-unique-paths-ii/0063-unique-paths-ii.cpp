class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

       
        vector<vector<int>> dp(n, vector<int>(m, 0));

        
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

       
        for(int i = 1; i < n; i++){
            if(obstacleGrid[i][0] == 0 && dp[i-1][0] == 1)
                dp[i][0] = 1;
        }

      
        for(int i = 1; i < m; i++){
            if(obstacleGrid[0][i] == 0 && dp[0][i-1] == 1)
                dp[0][i] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};
