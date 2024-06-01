class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val=0;
        for(auto it:nums) val^=it; 
        int f=0;
        int s=0;
        int i;
        for(i=0;i<32;i++){
            if(val&(1<<i)){
                break;
            }
        }
        for(auto it:nums){
            if(it&(1<<i)){
                f^=it;
            }
            else{
                s^=it;
            }
        }

        return {f,s};
    }
};      