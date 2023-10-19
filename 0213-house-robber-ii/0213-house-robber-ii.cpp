class Solution {
public:
int t[1001];
 int solve(vector<int> &nums,int pos){
        if(pos>=nums.size()){
            return 0;
        }

        if(t[pos]!=-1) 
        return t[pos];

        int in =nums[pos]+solve(nums,pos+2);
        int ex =solve(nums,pos+1);
         
        return t[pos]=max(ex,in);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        memset(t,-1,sizeof(t));
        int i=1;

        int l=solve(nums,i);
        memset(t,-1,sizeof(t));
        nums.pop_back();
        i=0;
        int r=solve(nums,i);
        
        return max(l,r);
    }
};