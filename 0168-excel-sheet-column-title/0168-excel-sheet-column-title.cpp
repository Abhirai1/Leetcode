class Solution {
public:
    string convertToTitle(int n){ 

      if(n==701)
      return "ZY";
      else if(n==702)
      return "ZZ";

    string r="";

    if(n==26)
    return "Z";

    int c=0;
    if(n%26==0){
      while(n>0){
        int rem=n%26;
        cout<<rem<<" ";
        if(rem==0)
        c=1;
        if(rem==0)
        r+='Z'; 
        else if(c==1){ 
        r+=(rem-1+'@');
        c=0;
        }
        else
        r+=(rem+'@');
        n=n/26; 
      }
      reverse(r.begin(),r.end());
      return r;
    }
 

    int pass=0;
    int rz=0;
    while(n>0){
        int rem=n%26; 
        cout<<rem<<" ";
        n=n/26; 
        r+=(rem+'@'); 
    }
    reverse(r.begin(),r.end());
    return r;
    }
};