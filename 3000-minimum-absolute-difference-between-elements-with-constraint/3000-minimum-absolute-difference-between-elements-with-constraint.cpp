class Solution {
public:
    
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;

        int ans=INT_MAX; 

        for(int i=x;i<nums.size();i++){
           s.insert(nums[i-x]);
            auto bound = s.upper_bound(nums[i]);
            if(bound!=s.end()){
                ans = min(ans, abs(nums[i]-*bound));
            }
            
            if(bound!=s.begin()){
                ans = min(ans, abs(*prev(bound) -nums[i]));
            }
        }
        return ans;
        
    }
};