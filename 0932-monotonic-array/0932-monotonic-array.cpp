class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc=0;
        int dec=0;
        // inc
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                inc++;
            }
        }

        //dec
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dec++;
            }
        }
        if(min(inc,dec)==0) return 1;
        return 0;
    }
};