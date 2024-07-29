class Solution {
public:
    void SieveOfEratosthenes(int n,vector<int> &prime)
{
   for (int p = 2; p * p <= n; p++) {
        if (prime[p] == 1) {
            for (int i = p * p; i <= n; i += p)
               prime[i] = 0;
        }
   }
}
    int nonSpecialCount(int l, int r) {
        int n=sqrt(r);
        vector<int> prime(n+2,1); 

        SieveOfEratosthenes(n+1,prime); 
        int cnt=0; 

        // [2----5] 2 3 4 5 
        for(int i=2;i<=n+1;i++){
            if(prime[i]){
                int temp=i*i;
                // cout<<i<<" ";
                if(temp>=l && temp<=r) cnt++; 
            }
        }

        return (r-l+1)-cnt;
    }
};