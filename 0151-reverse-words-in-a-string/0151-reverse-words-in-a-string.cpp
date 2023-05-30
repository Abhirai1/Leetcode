class Solution {
public:
    string reverseWords(string s) {
        
        
        stringstream ss; 
        ss << s; 
        s=""; 
         string word;
        stack<string> st;
        while(ss>>word){
            st.push(word);
        }
        while(!st.empty()){
            // st.push_back(word);
            s+=st.top();
            s+=" ";
            st.pop();
        }
        int n=s.size();
        s.erase(s.begin()+n-1);
        
        
        return s;
        
        // string ans="";
        // string temp="";
        // int t=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]==32){
        //         t++;
        //     } 
        //     else{
        //         break;
        //     }
        // }
        // int p=0;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]==32){
        //         p++;
        //     } 
        //     else{
        //         break;
        //     }
        // }
        // s+=" ";
        // int lol=1;
        // cout<<t<<" "<<p<<endl;
        // for(int i=t;i<s.size()-p;i++){
        //     if(s[i]!=32){
        //         temp+=s[i];
        //         lol=1;
        //     } 
        //     else{
        //         ans=temp+ans;
        //         if(i!=s.size()-p-1 && lol==1){ 
        //         ans=" "+ans; 
        //         lol=2;
        //         }
        //         temp="";
        //     }
        // } 
        // return ans;
    }
};