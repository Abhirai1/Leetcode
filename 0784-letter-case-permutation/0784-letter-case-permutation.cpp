class Solution {
public:
    
    void solve(string ip,string op,vector<string> &ans){
        if(ip.size()==0){
            ans.push_back(op); 
            return;
        } 
        
        if(ip[0]>=97 && ip[0]<=122){ 
            string op1=op; 
            string op2=op;
            op1.push_back(ip[0]);
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin());
            solve(ip,op1,ans); 
            solve(ip,op2,ans);
        } 
        else if(ip[0]>=65 && ip[0]<=92){
            string op1=op; 
            string op2=op;
            op1.push_back(ip[0]);
            op2.push_back(tolower(ip[0]));
            ip.erase(ip.begin());
            solve(ip,op1,ans); 
            solve(ip,op2,ans);
        }
        else{
            string op1=op; 
            op1.push_back(ip[0]);
             ip.erase(ip.begin());
            solve(ip,op1,ans);
        }
        
        return;
    
    }
    vector<string> letterCasePermutation(string ip) {
        vector<string> ans; 
        string op="";
        solve(ip,op,ans); 
        return ans;
    }
};