class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> ump; 
        int n=nums.size(); 

        ump[0]=1;
        int sum=0; 
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(ump.find(rem)!=ump.end()) ans+=ump[rem];

            ump[rem]++;
        }

        return ans;
    }
};