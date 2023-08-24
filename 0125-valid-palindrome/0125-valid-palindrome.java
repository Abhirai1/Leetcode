class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        String revstr1 = "";
        int i ;
        int strl = s.length();
        for (i = (strl-1); i >= 0 ; i--)
        {   
            char ch=s.charAt(i);
            if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||(ch>=48&&ch<=57)){
                revstr1 = revstr1 + s.charAt(i);
            }
            
        } 
        String revstr2 = "";
        for (i =0; i<strl ; i++)
        {   
            char ch=s.charAt(i);
            if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||(ch>=48&&ch<=57)){
                revstr2 = revstr2 + s.charAt(i);
            }
            
        }
        System.out.println(revstr1);
if (revstr2.equals(revstr1)){
return true;}
else 
return false;}}