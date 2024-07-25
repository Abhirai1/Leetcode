class Solution {
public:
    int minimumCost(int n, int m, vector<int>& hor, vector<int>& ver) {
        int ans=0; 

        sort(hor.begin(),hor.end(),greater<int>()); 
        sort(ver.begin(),ver.end(),greater<int>());

        n=hor.size();
        m=ver.size();

        int i=0;int j=0; 

        while(i<n && j<m){
            if(hor[i]>=ver[j]){
                ans+=hor[i]*(j+1);i++;
            }else{
                ans+=ver[j]*(i+1);j++;
            }
        }

        while(i<n){
            ans+=hor[i]*(j+1);i++;
        }

        while(j<m){
            ans+=ver[j]*(i+1);j++;
        }

        return ans;
    }
};