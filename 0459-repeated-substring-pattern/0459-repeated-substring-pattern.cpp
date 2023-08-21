class Solution {
public:

    void findDiv(vector<int> &div,int n){
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                div.push_back(i);
            }
        }
    }

    bool repeatedSubstringPattern(string s) {

        unordered_map<char,int> ump; 
        for(auto it:s){
            ump[it]++;
        }
        if(ump.size()==1 && ump[s[0]]>1){  
        return true; 
        }
        else if(ump.size()==1 && ump[s[0]]==1){
            return false;
        }

        vector<int> div; 
        int n=s.size();
        findDiv(div,n); 

        for(auto &it:div){
            unordered_map<string,int> ump;
            string t="";
            for(int i=0;i<n/it;i++){
                t+=s.substr(0,it); 
               
            }
            if(t==s)
            return true;
        }

        return false;

    }
};