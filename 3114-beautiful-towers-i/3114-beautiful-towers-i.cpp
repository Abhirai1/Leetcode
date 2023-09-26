class Solution {
public:
    long long int solve(int ind,vector<int> maxHeights){
        int m1=maxHeights[ind];
         long long int ans=maxHeights[ind];
        for( long long int i=ind-1;i>=0;i--){
            m1=min(m1,maxHeights[i]);
            ans+=min(m1,maxHeights[i]);

            
        }
        
         long long int n=maxHeights.size();
         int m2=maxHeights[ind];
         for( long long int i=ind+1;i<n;i++){
               m2=min(m2,maxHeights[i]);
             ans+=min(m2,maxHeights[i]);
             
        } 
        
        return ans;
    }
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
         int maxi=INT_MIN; 
         long long  int ans=INT_MIN;
        for(int i=0;i<maxHeights.size();i++){
                long long int t= solve(i,maxHeights);
                ans=max(ans,t);
        }
        return ans;
    }
};