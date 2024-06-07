class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> ump; 
        for(auto it:dictionary) ump[it]++; 

        vector<string> ans;

        stringstream s(sentence); 

        string temp="";

        while(s >> temp){
            int len=INT_MAX; 
            string kill="";

            int n=temp.size();

            for(int i=0;i<n;i++){
                kill.push_back(temp[i]);
                if(ump.find(kill)!=ump.end()) break;
            }

            if(kill.size()==0) ans.push_back(temp);
            else ans.push_back(kill);
        }

        string finalAns=""; 
        for(auto it:ans){
            finalAns+=it; 
            finalAns.push_back(' ');
        }

        finalAns.pop_back();

        return finalAns;
    }
};