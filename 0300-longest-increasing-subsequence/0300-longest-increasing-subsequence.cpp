class Solution {
public:
    int t[2501][2501];
    int solve(vector<int> &nums,int val,int ind,int pass){

        if(ind==nums.size()) return 0; 


        if(pass!=-1 && t[ind][pass]!=-1) return t[ind][pass];

        int take=0;
        if(pass==-1 || nums[ind]>nums[pass]){
            take=1+solve(nums,val=nums[ind],ind+1,ind);
        }
        int skip=solve(nums,val,ind+1,pass);

        if(pass!=-1) 
        return t[ind][pass]=max(take,skip);

        return max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));

        if(nums.size()==1) return 1;
        else if(nums.size()==2){
            if(nums[0]<nums[1]) return 2;
            else return 1;
        }
        
        // for(int i=0;i<=nums.size();i++) cout<<t[i]<<" "; 
        return solve(nums,INT_MIN,0,-1);
    }
};