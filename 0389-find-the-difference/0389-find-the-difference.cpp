class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char,int> ump;
        for(auto it:s){
            ump[it]++;
        }

        for(auto it:t){
            if(ump.find(it)==ump.end())
            return it;
            ump[it]--;
            if(ump[it]==0){
                ump.erase(it);
            }
        }

        return 'a';

    }
};