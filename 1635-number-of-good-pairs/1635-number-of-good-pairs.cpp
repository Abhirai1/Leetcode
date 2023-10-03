class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> ump; 
        for(auto it:nums){
            ump[it]++;
        }
        int ans=0;
        for(auto it:ump){
            if(it.second>1){
                ans+=((it.second*(it.second-1))/2);
            }
        }
        return ans;
    }
};