class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int p=processorTime.size(); 
        int t=tasks.size(); 
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end()); 
        t--;
        int maxi=INT_MIN;
        for(int i=0;i<p;i++){
            for(int k=0;k<4;k++){
                maxi=max(maxi,processorTime[i]+tasks[t]);
                t--;
            }
        }
        return maxi;
    }
};