class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        int balance = 0; 
        // int kami=0; 
        int start=0; 
        
        
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0))
            return -1;
        for(int i=0;i<n;i++){
            balance+=(gas[i]-cost[i]); 
            
            if(balance<0){
                // kami+=balance;
                start=i+1; 
                balance=0;
            }
        }
        
            return start;
    
    }
};