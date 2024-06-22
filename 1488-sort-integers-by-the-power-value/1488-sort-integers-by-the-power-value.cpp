class Solution {
public:
        int power(int n, map<int,int> &dp){
        if(n == 1) return 0;
        if(dp.find(n) != dp.end()) return dp[n];
        if(n % 2 == 0) return dp[n] = 1 + power(n / 2, dp);
        return dp[n] = 1 + power(3 * n + 1, dp);
    }
    int getKth(int lo, int hi, int k) {
        map<int,int> dp;
        multimap<int,int> m;        
        for(int i = lo; i <= hi; i++){
            int val = power(i,dp);
            m.insert({val,i});
        }
        for(auto it : m){
            k--;
            if(k == 0) return it.second;
        }
        return -1;
    }
};