class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        sort(intervals.begin(),intervals.end()); 
        intervals.push_back({INT_MAX,INT_MAX});
        if(intervals.size()==1) return intervals;
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=e){
                if(intervals[i][1]>e)
                e=intervals[i][1];
            }
            else{
                vector<int> temp; 
                temp.push_back(s);
                temp.push_back(e);
                s=intervals[i][0];
                e=intervals[i][1];
                ans.push_back(temp);
            }
        } 

        return ans;  
    }
};