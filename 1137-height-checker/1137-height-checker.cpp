class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> temp=h;
        sort(h.begin(),h.end()); 
        int cnt=0; 
        for(int i=0;i<h.size();i++){
            if(h[i]!=temp[i]) cnt++;
        }
        
        return cnt;
    }
};