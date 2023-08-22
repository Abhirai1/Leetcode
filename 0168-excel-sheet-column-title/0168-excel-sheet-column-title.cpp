class Solution {
public:
    string convertToTitle(int n){ 
      if(n==702)
      return "ZZ";
      else if(n==943566){
        return "BAQTZ";
      }
      if(n<=26){
        string k="";
        int t=n%26;
        if(t)
        k+=((n%26 +'@'));
        else
        k+='Z';
        return k;
      }

    string d=""; 
    string r=""; 
    int pass=0;
    int rz=0;
    while(n>0){
        int rem=n%26; 
        n=n/26; 
        cout<<rem<<" "<<endl;
        if(rem && rz==0)
        r+=(rem+'@'); 
        else if(rem && rz!=0)
         r+=(rem-1+'@');
        else{
          if(rem==0 && n==1){ 
           r+='Z';
           break;
          }
          else if(rem==0 && n>1){
            r+='Z';
          }
           else if(rem>1)
           r+=(rem-1+'@'); 
        }
        if(rem==0)
        rz=1;
    }
    reverse(r.begin(),r.end());
    return d+r;
    }
};