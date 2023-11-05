class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(); 
        int t=((n*(n+1)))/2; 

        int sum=0; 
        for(auto it:nums){
            sum+=it;
        } 
        cout<<t<<" "<<sum<<endl;
        return abs(sum-t);  
    }
};