class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a1=0,a2=0,b=0; 

        for(auto it:nums){
           if(it<10) a1+=it;
           else if(it<100) a2+=it;
            else b+=it;
        }

        return max(a1,a2)>b+min(a1,a2) ? true : false;
    }
};