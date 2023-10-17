class Solution {
public:
//    int t[1001];
   
//     int solve(vector<int> &nums,int pos){
//         if(pos>=nums.size()){
//             return 0;
//         }

//         if(t[pos]!=-1) 
//         return t[pos];

//         int in =nums[pos]+solve(nums,pos+2);
//         int ex =solve(nums,pos+1);
         
//         return t[pos]=max(ex,in);
//     }
    int rob(vector<int>& nums) {
        int t[1001];
        memset(t,-1,sizeof(t));
        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=nums.size();i++){
            int inc=nums[i-1] + t[i-2];
            int exc=t[i-1];
            t[i]=max(inc,exc);
        }    
        return t[nums.size()];
    }
};