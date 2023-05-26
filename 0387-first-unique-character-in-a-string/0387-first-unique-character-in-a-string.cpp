class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<pair<int,int>> ans(26,{0,0}); 
        
        for(int i=0;i<s.size();i++){
            
            ans[(s[i]-97)]={(ans[(s[i]-97)].first+1) , i};
            
        }
        int mini=INT_MAX;
        
        for(auto &it:ans){
            if(it.first==1){
                mini=min(mini,it.second);
            }
        }
        if(mini==INT_MAX)
            mini=-1;
        return mini;
    }
};