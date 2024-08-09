class Solution {
public:
#define lli long long int
    lli t[30001];
     int binarySearch(vector<vector<int>>& rides,int val){
        int s=0,e=rides.size()-1;
        int ans=rides.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(rides[mid][0]>=val){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    lli solve(vector<vector<int>>& rides,int n,int ind){
        if(ind>=n) return 0; 

        /*
        BS -> good move
        but one doubt -> pair cause confusion
        target to get next index to pic but issue ye hai 
        */

        if(t[ind]!=-1) return t[ind];

        lli take=0,skip=0;
        lli idx = binarySearch(rides,rides[ind][1]);
        take = (rides[ind][1]-rides[ind][0] + rides[ind][2]) + solve(rides,n,idx);
        skip=solve(rides,n,ind+1);
                  
        return t[ind]=max(take,skip);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset(t,-1,sizeof(t));
        sort(rides.begin(),rides.end());
        return solve(rides,rides.size(),0);
    }
};