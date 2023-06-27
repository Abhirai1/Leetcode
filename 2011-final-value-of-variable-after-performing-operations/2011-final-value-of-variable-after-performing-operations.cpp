class Solution {
public:
    int finalValueAfterOperations(vector<string>& nums) {
        
        int plus=0; 
        int minus=0; 
        
        for(auto &it:nums){
            int n=it.size(); 
            if(it[0]=='+' || it[2]=='+')
                plus++; 
            else
                minus++;
        }
        
        return (plus-minus);
        
    }
};