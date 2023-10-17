class Solution {
public:
   int t[1001];
   
    int solve(vector<int> &nums,int pos){
        if(pos>=nums.size()){
            return 0;
        }

        if(t[pos]!=-1) 
        return t[pos];

        int in =nums[pos]+solve(nums,pos+2);
        int ex =solve(nums,pos+1);
         
        return t[pos]=max(ex,in);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int i=0;
        solve(nums,i);
        // for(auto it:t)
        // cout<<it<<" ";        
        return t[0];
    }
};