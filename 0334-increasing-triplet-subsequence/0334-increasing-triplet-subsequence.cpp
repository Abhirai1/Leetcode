class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;

        int n=nums.size(); 

        /*
        ip => 1,2,3,4,5
        f=
        */


        for(int i=0;i<n;i++){
            if(nums[i]<=first) first = nums[i];
            else if(nums[i]<=second) second = nums[i]; 
            else return true; // bda bhai aa gya, aaukat me

            // cout<<first<<" "<<second<<" "<<nums[i]<<endl;
        }

        return false;
    }
};