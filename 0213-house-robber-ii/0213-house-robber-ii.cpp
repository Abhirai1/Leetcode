class Solution {
public:

    int t[101];
    int bottomUp(vector<int> ans,int s,int n){

        memset(t,-1,sizeof(t));
        t[0]=0;
        t[1]=ans[s];

        for(int i=2;i<=n;i++){
            int pick=ans[i-1]+t[i-2];
            int notpick=t[i-1];
            t[i]=max(pick,notpick);
        }

        return t[n];

    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }

        vector<int> temp=nums;
        int n=nums.size(); 

        temp.erase(temp.begin());
        int notpick=bottomUp(temp,0,n-1);
        nums.pop_back();
        int pick=bottomUp(nums,0,n-1);  

        return max(pick,notpick);
    }
};