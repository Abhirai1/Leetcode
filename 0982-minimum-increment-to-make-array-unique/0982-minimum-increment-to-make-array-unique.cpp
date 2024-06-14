class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans=0; int n=nums.size(); 
        sort(nums.begin(),nums.end());
        // for(auto it:nums) cout<<it<<" ";
        // cout<<endl;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                ans+=(abs(nums[i]-nums[i-1]) + 1);
                nums[i]=nums[i-1]+1;
            }
        }
        // for(auto it:nums) cout<<it<<" ";
        return ans;
    }
};