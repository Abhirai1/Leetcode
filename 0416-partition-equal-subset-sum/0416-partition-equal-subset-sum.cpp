class Solution {
public:
    int t[201][20001];
    bool  solve(vector<int>& nums,int sum,int ind){
        if(sum==0) return true; 
        if(sum<0) return false;
        
        if(ind<0) return false; 

        if(t[ind][sum]!=-1) return t[ind][sum];
        
        int take=solve(nums,sum-nums[ind],ind-1); 
        int skip=solve(nums,sum,ind-1);
        
        return t[ind][sum]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int N=nums.size();
        int sum=0;
        for(int i=0;i<N;i++) sum+=nums[i];
        if(sum&1)return false;
        sum/=2;
        return solve(nums,sum,N-1);
    }
};