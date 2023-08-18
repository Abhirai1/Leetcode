class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        int final=INT_MAX;
        for(auto &it:strs){
            int cnt=0;
            int n=min(it.size(),s.size()); 
            for(int i=0;i<n;i++){
                if(s[i]==it[i]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            final=min(cnt,final);
            cnt=0;
        } 
        string ans=""; 
        for(int i=0;i<final;i++){
            ans+=s[i];
        }
        return ans;
    }
};