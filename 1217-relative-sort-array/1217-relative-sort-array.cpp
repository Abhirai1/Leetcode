class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> ump; 
        for(int i=0;i<arr1.size();i++){
            ump[arr1[i]]++;
        } 
        vector<int> ans;
        vector<int> temp;
        for(int i=0;i<arr2.size();i++){
            // if(ump.find(arr2[i])==ump.end()){
            //     temp.push_back(arr2[i]);
            // }
            // else{
                int kill = ump[arr2[i]]; 
                while(kill--){
                    ans.push_back(arr2[i]);
                }
                ump.erase(arr2[i]);
            // }
        } 
        // for(int i=0;i<temp.size();i++){
        //     ans.push_back(temp[i]);
        // }
        // temp.clear(); 
        for(auto &it:ump){
           int kill = it.second; 
            while(kill--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};