class Solution {
public:
    #define lli long long int
    long long maximumTripletValue(vector<int>& nums) {
        lli n=nums.size(); 
        lli ans=0;
        vector<lli> lmaxi(n); 
        vector<lli> rmax(n);

        rmax[n-1]=(lli)(nums[n-1]);
        for(lli i=n-2;i>=0;i--){
            rmax[i]= max(rmax[i+1],(lli)nums[i]);
        }
        lmaxi[0]=(lli)nums[0]; 
        for(lli i=1;i<n;i++){
            lmaxi[i]= max(lmaxi[i-1],(lli)nums[i]);
        }
        for(lli i=1;i<n-1;i++){
            ans=max(ans,((lmaxi[i-1]-nums[i])*rmax[i+1]));
        }
        
        return ans;
    }
};