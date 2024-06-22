class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(); 
        // for(int i=0;i<n;i++) nums[i]=(nums[i]%2); 

        unordered_map<int,int> ump;

        int sum=0; ump[0]=1; int ans=0;

        for(auto it:nums){
            sum+=(it%2); 

            if(ump.find(sum-k)!=ump.end()) ans+=ump[sum-k];

            ump[sum]++;
        }

        return ans;
    }
};