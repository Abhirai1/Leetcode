class Solution {
public:
    #define ppr pair<int,int>
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<ppr> ip; 
        int n=profits.size(); 

        for(int i=0;i<n;i++) ip.push_back({capital[i],profits[i]});

        sort(ip.begin(),ip.end());
        
        int i=0; 

        priority_queue<int> pq;

        while(k--){
            while(i<n && ip[i].first <= w) {
                pq.push(ip[i].second);
                i++;
            }

            if(pq.size()==0) break;

            w+=pq.top(); 
            pq.pop();
        }

        return w;
    }
};