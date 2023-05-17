class Solution {
    private: 
//     void solve(vector<int> nums , vector<int> value , int index , vector<vector<int>>& ans ){
//         if(index >= nums.size()){
//             ans.push_back(value);
//             return;
//         } 

//         // exclude wala call 
//         solve(nums,value,index+1,ans); 

//         // include wala case
//         int element = nums[index]; 
//         value.push_back(element);
//         solve(nums,value,index+1,ans); 


//     }
public:
    
    void solve(vector<int> ip, vector<int> op,vector<vector<int>> &ans){
        if(ip.size()==0)
        {
            ans.push_back(op);
            return;
        } 
        
        vector<int> op1=op; 
        vector<int> op2=op;
        op2.push_back(ip[0]); 
        ip.erase(ip.begin()); 
        
        solve(ip,op1,ans); 
        solve(ip,op2,ans); 
        
        return;
    }
        
        
    vector<vector<int>> subsets(vector<int>& ip) {
        vector<vector<int>> ans; 
        vector<int> op;
        solve(ip,op,ans); 
        return ans;
        
        // vector<vector<int>> ans;
        // vector<int> value;
        // int index=0; 
        // solve(nums,value,index,ans); 
        // return ans;
    }
};