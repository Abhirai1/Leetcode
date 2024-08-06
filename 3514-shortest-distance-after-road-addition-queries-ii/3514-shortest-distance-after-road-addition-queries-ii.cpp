class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> unst; 
        for(int i=0;i<n;i++) unst.insert(i);

        vector<int> ans; 

        for(auto it:queries){
            int u=it[0];int v=it[1]; 

            vector<int> temp; 
            auto t=unst.upper_bound(u);

            while(t!=unst.end() && *t<v){ temp.push_back(*t);t++;}

            for(auto it:temp) unst.erase(it);

            ans.push_back(unst.size()-1);
        }

        return ans;
    }
};