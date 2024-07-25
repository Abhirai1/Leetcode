class Solution {
public:

    void  solve(int n,vector<string> &ans,string temp,int cnt){
        if(n==0){
            ans.push_back(temp);
            return;
        }


        if(cnt==1){
            temp.push_back('1');
            solve(n-1,ans,temp,0);
            // temp.pop_back();
        }else{
            temp.push_back('1');
            solve(n-1,ans,temp,0);
            temp.pop_back();

            temp.push_back('0');
            solve(n-1,ans,temp,1);
            // temp.pop_back();
        }



        // return;
    }
    vector<string> validStrings(int n) {
        vector<string> ans; 
        solve(n,ans,"",0);
        return ans;
    }
};