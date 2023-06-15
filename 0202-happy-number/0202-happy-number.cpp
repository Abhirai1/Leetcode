class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int,int> ump;
        if(n==1)
            return true; 
        ump[n]++;
        while(1){
            
           int temp=0;
            while(n>0){
                temp += ((n%10)*(n%10)); 
                n=n/10;
            }
            if(temp==1)
                return true;
            ump[temp]++; 
            if(ump[temp]>1)
                return false;
            n=temp;
            
        }
        
        return false;
        
         
    }
};