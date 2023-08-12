class Solution {
public:
    bool isPalindrome(int x) {
        string n=to_string(x);
       for(int i=0,j=n.size()-1;j>=i;j--,i++){
           if(n[i]!=n[j]) return false;
       } 
    return true;
    }
};