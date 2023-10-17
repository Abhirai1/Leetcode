class Solution {
public:  
   
    // int cnt(int n,int dp[]){
    //     if(n<=1){ 
    //         return 1;
    //     }
    //     if(dp[n]!=-1)
    //     return dp[n]; 

    //     return dp[n]=(cnt(n-1,dp)+ cnt(n-2,dp));

    // }
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        int dp[n+1];
        memset(dp,-1,sizeof dp);
       int lp=1;
       int p=1;
       int ans=0;
        for(int i=2;i<=n;i++){
            ans=p+lp; 
            lp=p;
            p=ans;
        }
        // cnt(n,dp);

        return ans;
    }
};