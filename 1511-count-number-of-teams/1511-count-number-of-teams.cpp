class Solution {
public:
    int t[1001][1001][4];
    int solve(vector<int>& ip,int prev,int ind,int n,int k){
        if(k==0) return 1;
        if(ind>=n) return 0; 
        int take=0,skip=0;

        if(prev!=-1 && t[prev][ind][k]!=-1) return t[prev][ind][k];

        if(prev==-1 || ip[ind]>ip[prev]){
            take=solve(ip,ind,ind+1,n,k-1);
        }
        skip=solve(ip,prev,ind+1,n,k);
        if(prev!=-1) t[prev][ind][k]=take+skip;
        
        return take+skip;
    }
    int numTeams(vector<int>& rating) {
        memset(t,-1,sizeof(t));
        int ans=0;
        ans+=solve(rating,-1,0,rating.size(),3);
        reverse(rating.begin(),rating.end());
        memset(t,-1,sizeof(t));
        ans+=solve(rating,-1,0,rating.size(),3);

        return ans;
    }
};