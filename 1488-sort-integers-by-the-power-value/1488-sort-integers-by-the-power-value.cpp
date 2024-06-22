class Solution {
public:
   
    int power(int n){
        if(n == 1) return 0;
        
        if(n % 2 == 0) return  1 + power(n / 2);
        return 1 + power(3 * n + 1);
    }
    int getKth(int lo, int hi, int k) {
        
        multimap<int,int> m;        
        for(int i = lo; i <= hi; i++){
            int val = power(i);
            m.insert({val,i});
        }
        for(auto it : m){
            k--;
            if(k == 0) return it.second;
        }
        return -1;
    }
};