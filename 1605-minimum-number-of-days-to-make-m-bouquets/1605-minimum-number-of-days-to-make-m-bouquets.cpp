class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k,int mid){

        long long int cnt=0;
        for(auto it:bloomDay){
            if(it<=mid){
                cnt++; 
                if(cnt==k){ 
                    m--; 
                    if(m==0) return true;
                    cnt=0;
                }

                
            }else{
                cnt=0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int s=1;
        long long int e=INT_MAX; 
        int ans=-1;
        while(s<=e){
           long long int mid=s+(e-s)/2; 

            if(isPossible(bloomDay,m,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        return ans;
    }
};