class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> final(2);
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i]; 
            if(ans.find(temp)==ans.end()){
                ans[nums[i]]=i;
            } 
            else{
                final[0]=i; 
                final[1]=ans[temp];
                break;
            }
        } 

        return final;

    
    }
};