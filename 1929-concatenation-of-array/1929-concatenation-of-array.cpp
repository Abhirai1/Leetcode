class Solution {
public:
    
    void copy(vector<int> &nums,vector<int> &ans){
         for(auto &it:nums){
            ans.push_back(it);
        }
    }
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector<int> ans=nums;
        // copy(nums,ans);
        copy(nums,ans);
        return ans;
        
    }
};