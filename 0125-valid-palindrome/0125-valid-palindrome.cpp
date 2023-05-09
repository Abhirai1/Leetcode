class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57)){
                char c = tolower(s[i]); 
                s[i]=c;
                continue;
            } 
            else{
                s.erase(i,1);
                --i;
            }
        } 
        cout<<s<<endl;
        int i=0; 
        int j=s.size()-1; 
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            } 
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};