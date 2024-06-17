class Solution {
public:

    // let's analyse time complexity

    int t[10001];
    int solve(vector<int>& coins,int amount){
        if(amount==0) return 0; 
        if(amount<0) return 100000;

        if(t[amount]!=-1) return t[amount];

        int take=100000;
        for(auto it:coins){
            if(it<=amount){
                take=min(1+solve(coins,amount-it),take);
            }
        }

        return t[amount]=take;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        int t[amount+1];
        t[0]=0; 
        for(int i=1;i<=amount;i++) t[i]=100000; 

        for(int amt=1;amt<=amount;amt++){
            for(auto it:coins){
                if(it<=amt){
                    t[amt] = min(1+t[amt-it],t[amt]);
                }
            }
        }

        return t[amount]==100000 ? -1 : t[amount];
    }
};