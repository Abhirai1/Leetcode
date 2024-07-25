class Solution {
public:
    int minimumLength(string s) {
        int ans=0; 
        unordered_map<char,int> ump; 
        for(auto it:s) ump[it]++; 

        for(auto it:ump){
           if(it.second<3) ans+=it.second; 
           else if(it.second&1) ans+=1;
           else if(it.second %2==0) ans+=2;
        }

        return ans;
    }
};