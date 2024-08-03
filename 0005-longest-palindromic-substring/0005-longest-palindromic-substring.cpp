class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(string &s,int i,int j){
        if(i>=j) return true;

        if(t[i][j]!=-1) return t[i][j];

        if(s[i]==s[j] && isPalindrome(s,i+1,j-1)) return true;

        return false;
    }
    string longestPalindrome(string s) {

        memset(t,-1,sizeof(t));

        int n=s.size();
        int ans=1; 
        vector<int> ind(2,0);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    if((j-i+1)>ans) {
                        ans=j-i+1; 
                        ind = {i,j};
                    }
                }
            }
        }

        string temp=""; 
        for(int i=ind[0];i<=ind[1];i++) temp.push_back(s[i]);

        return temp;
    }
};