class Solution {
public:
vector<vector<int>>  ans;
    void fn(vector<int>& op,vector<int>& ip,int sum,int i){
        if(sum==0){
            ans.push_back(op);
            return;
        }
        if(i>=ip.size() || sum<0) return;

        op.push_back(ip[i]);
        fn(op,ip,sum-ip[i],i);
        op.pop_back();
        fn(op,ip,sum,i+1);
        
    }

    vector<vector<int>> combinationSum(vector<int>& ip, int target) {
       vector<int> op;
        fn(op,ip,target,0);
        return ans;
    }
};