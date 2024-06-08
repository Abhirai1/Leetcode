class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump; 
        ump[0]=-1; 

        if(nums.size()<2) return false;

        int sum=0; 
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]; 

            // i----------j (window) ? okay
            int rem=sum%k; 
            if(ump.find(rem)!=ump.end()){
                if(i-ump[rem]>1) return true;
            }else{
                ump[rem]=i;
            }
        }
        return false;
    }
};