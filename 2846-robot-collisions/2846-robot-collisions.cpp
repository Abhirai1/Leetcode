class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        vector<int> ans; 
        stack<pair<int,int>> st; 
        vector<pair<int,int>> ip; 

        for(int i=0;i<n;i++) ip.push_back({positions[i],i});
        
        sort(ip.begin(),ip.end()); 

        for(auto it:ip){
            int pos=it.first; 
            int ind=it.second; 
            char dir=directions[ind]; 
           
            if(st.size()==0 || dir=='R'){
                st.push({pos,ind});
            }
            else{
                while(st.size()>0 && directions[st.top().second]=='R' && dir!=directions[st.top().second] && healths[ind]>healths[st.top().second]){
                    healths[st.top().second]=0;
                    healths[ind]--;
                    st.pop();
                }

                if(st.size()>0 && directions[st.top().second]=='R' && dir!=directions[st.top().second] && healths[ind]==healths[st.top().second]){
                    healths[st.top().second]=0;
                    healths[ind]=0;
                    st.pop();
                    continue;
                }

                if(st.size()>0 && directions[st.top().second]=='R' && dir!=directions[st.top().second] && healths[ind]<healths[st.top().second]){
                    healths[st.top().second]--;
                    healths[ind]=0;
                }

                if((st.size()==0 && healths[ind]>0) || (st.size()>0 && dir==directions[st.top().second]))  st.push({pos,ind});

            }
        }

        for(auto it:healths) if(it!=0) ans.push_back(it);

        return ans;
    }   
};