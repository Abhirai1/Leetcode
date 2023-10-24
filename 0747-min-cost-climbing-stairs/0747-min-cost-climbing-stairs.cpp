class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int i){
        if(i>=cost.size()) return 0; 

        if(t[i]!=-1) return t[i];

        int one=solve(cost,i+1);
        int two=solve(cost,i+2);

        return t[i] = cost[i]+min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        int i=0;
        return min(solve(cost,i),solve(cost,i+1));
    }
};