class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int i=0;
        int j=0; 
        unordered_map<int,int> ump;
        int ans=INT_MIN;
        while(j<nums.size()){
            ump[nums[j]]++;
            ans=max(ans,ump[nums[j]]);
            if((j-i+1-ans)>k){
                ump[nums[i]]--; 
                i++;
            }
            j++;
        }
        return ans;
    }
};