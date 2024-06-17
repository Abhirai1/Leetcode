class Solution {
public:
    int mod = pow(10,9) + 7;
    int helper(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(j == t.size()) return dp[i][j] = 1;
        if(i == s.size()) return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != t[j]){
            return dp[i][j] = helper(s,t,i+1,j,dp);
        }
        int pick = helper(s,t,i + 1, j + 1,dp);
        int not_pick = helper(s,t,i + 1, j,dp);
        return dp[i][j] = (pick + not_pick) % mod;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s,t,0,0,dp);
    }
};