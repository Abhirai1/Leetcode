class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k=nums.size()/3;
        vector<int> ans;
        unordered_map<int,int> ump; 
        for(auto it:nums){
           ump[it]++;
        }
        for(auto it:ump){
            if(it.second>k) ans.push_back(it.first);
        }

        return ans;
    }
};