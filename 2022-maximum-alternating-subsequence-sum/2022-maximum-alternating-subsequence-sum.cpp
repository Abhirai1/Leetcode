class Solution {
public:
    // long long int t[100006][2];
    // long long int  solve(vector<int>& nums,int ind,int cnt){

    //     if(ind==nums.size()){
    //         return 0;
    //     } 

    //     if(t[ind][cnt]!=-1) return t[ind][cnt];

    //     long long int  skip= solve(nums,ind+1,cnt);
    //     long long int take;
    //     if(cnt==0)
    //     take=nums[ind]+solve(nums,ind+1,!cnt);
    //     else
    //     take=((-1)*nums[ind])+solve(nums,ind+1,!cnt);
        
    //     return t[ind][cnt] = max(skip,take);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        // int i=0;
       long long int n=nums.size();
       long long int t[100001][2];
       long long int even=0;
        long long int odd=1;
        memset(t,0,sizeof(t));

        t[0][even]=0;
        t[0][odd]=0;
        for(int i=1;i<=n;i++){
            t[i][even]=max(t[i-1][odd]-nums[i-1],t[i-1][even]);
            t[i][odd]=max(t[i-1][even]+nums[i-1],t[i-1][odd]);
        }

        return max(t[n][odd],t[n][even]);
    }
};