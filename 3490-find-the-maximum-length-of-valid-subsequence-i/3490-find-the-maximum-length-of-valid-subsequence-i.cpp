class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> same(2,0),diff(2,0); 

        for(auto it:nums){
            same[it%2]++; 
            // 01 , 10
            diff[it%2]=max(diff[it%2],diff[1-it%2]+1);
        }

        return max(*max_element(same.begin(),same.end()),*max_element(diff.begin(),diff.end()));
    }
};