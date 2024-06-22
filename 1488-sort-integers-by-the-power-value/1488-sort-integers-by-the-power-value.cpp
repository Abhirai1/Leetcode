class Solution {
public:
    int t[1000000];
    int power(int n){
        if(n == 1) return 0;
        if(t[n]!=-1) return t[n];
        if(n % 2 == 0) return t[n] = 1 + power(n / 2);
        return t[n] = 1 + power(3 * n + 1);
    }
    int getKth(int lo, int hi, int k) {
        memset(t,-1,sizeof(t));
        map<int,int> dp;
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