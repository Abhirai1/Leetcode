class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int ans=0;
        int n=x;
        while(n>0){
        int digit=n%10;
        if(INT_MAX/10<ans){
            return false;
        }
        ans=ans*10+digit;
        n=n/10;
        }
        
        if(ans==x){
return true;
        }
        else{
        return false;
        }
    }
   
};