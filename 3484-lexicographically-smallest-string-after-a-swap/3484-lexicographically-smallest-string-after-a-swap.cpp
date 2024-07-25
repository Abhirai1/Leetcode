class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size(); 
        
        for(int i=1;i<n;i++){
            if(s[i-1]>s[i] && ((s[i-1]-'0') + (s[i]-'0'))%2==0){swap(s[i-1],s[i]);break;}
        }
        
        return s;
    }
};