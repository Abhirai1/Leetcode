class Solution {
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
    vector<vector<int>> subsetsWithDup(vector<int>& ip) {
        sort(ip.begin(),ip.end());
        vector<vector<int>> ans; 
        vector<int> op;
        solve(ip,op,ans); 
        map<vector<int>,int> ump; 
        for(auto &it:ans){
            ump[it]++;
        } 
        ans.clear(); 
        for(auto &it:ump){
            ans.push_back(it.first);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};