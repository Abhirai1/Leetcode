class Solution {
public:
    int t[501][26];
    int solve(vector<int>& nums,int i,int k){
        if(t[i][k]!=-1) return t[i][k];
        int maxi=1;
        for(int j=i-1;j>=0;j--){
            if(nums[i]!=nums[j] && k>0){
                maxi=max(maxi,1+solve(nums,j,k-1));
            }else if(nums[i]==nums[j]){
                maxi=max(maxi,1+solve(nums,j,k));
            }
        }

        return t[i][k]=maxi;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int  ans=0; 
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(nums,i,k));
        }

        return ans;
    }
};