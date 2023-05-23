class Solution {
public:

    void solve(vector<int> ans,int k,int index,int &final){
        if(ans.size()==1){ 
            final = ans[0];
            cout<<final<<endl;
            return;
        }
        index = (k+index)%(ans.size()); 
        ans.erase(ans.begin() + index);
        solve(ans,k,index,final);
        return ;
    } 
    
    int findTheWinner(int n, int k) {
        k=k-1; 
        vector<int> ans(n); 
        int final=9;
        int temp=1; 
        for(int i=0;i<n;i++){
            ans[i]=temp; 
            temp++;
        }
        int index=0;
        solve(ans,k,index,final);
        return final;
    }
};