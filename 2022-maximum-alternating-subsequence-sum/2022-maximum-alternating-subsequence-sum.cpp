class Solution {
public:
    long long int t[100006][2];
    long long int  solve(vector<int>& nums,int ind,int cnt){

        if(ind==nums.size()){
            return 0;
        } 

        if(t[ind][cnt]!=-1) return t[ind][cnt];

        long long int  skip= solve(nums,ind+1,cnt);
        long long int take;
        if(cnt==0)
        take=nums[ind]+solve(nums,ind+1,!cnt);
        else
        take=((-1)*nums[ind])+solve(nums,ind+1,!cnt);
        
        return t[ind][cnt] = max(skip,take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int i=0;
        int cnt=0;
        memset(t,-1,sizeof(t));
        return solve(nums,i,cnt);
    }
};