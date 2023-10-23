class Solution {
public:

    int t[1001][1001];

    int solve(vector<vector<int>>& pairs,int n,int prev,int ind){

        if(ind==n) return 0; 


        if(prev!=-1 && t[ind][prev]!=-1) return t[ind][prev];

        int take=0,skip=0;
        if(prev==-1 || pairs[ind][0]>pairs[prev][1]){
            take=1+solve(pairs,n,ind,ind+1);
        }
        skip=solve(pairs,n,prev,ind+1);
        if(prev!=-1){
            t[ind][prev]=max(take,skip);
        }

        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {

        memset(t,-1,sizeof(t));

        sort(pairs.begin(),pairs.end());
        if(pairs.size()==1) return 1;
        int n=pairs.size();
        return solve(pairs,n,-1,0);
    }
};