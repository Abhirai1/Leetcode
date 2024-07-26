class Solution {
public:
    #define lli long long int
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        lli n=nums.size();
        vector<lli> diff(n,0); 

        for(lli i=0;i<n;i++) diff[i]=target[i]-nums[i];

        lli curr=0,prev=0; 
        lli ans=0;
        for(lli i=0;i<n;i++){
            curr=diff[i]; 

            // sign change
            if((curr<0 && prev>0) || (curr>0 && prev<0))ans+=abs(curr);
            else if(abs(curr)>abs(prev))ans+=abs(curr-prev);
        
            prev=curr;
        }
        return ans;
    }
};