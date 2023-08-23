class Solution {
public:

    string reorganizeString(string s) {

        unordered_map<char,int> ump; 
        for(auto it:s)
        ump[it]++;

        priority_queue<pair<int,char>> pq; 
        for(auto it:ump)
        pq.push({it.second,it.first});

        string ans="";

        while(pq.size()>1){

            auto t1=pq.top();
            pq.pop(); 
            auto t2=pq.top(); 
            pq.pop();

            ans+=t1.second; 
            ans+=t2.second; 

            if(t1.first>1){
                pq.push({t1.first-1,t1.second});
            }
            if(t2.first>1){
                pq.push({t2.first-1,t2.second});
            }

        }

        if(pq.size()==1){
            if(pq.top().first>1)
            return "";
            else
            ans+=pq.top().second;
        }

        return ans;




        // int rem=0;
        // char remch;
        // for(auto it:ump){ 
        // rem+=it.second;
        // remch=it.first;
        // }

        // int bchesapce=0;
        // for(int i=0;i<s.size();i++){
        //     if(temp[i]=='A')
        //     bchesapce++;
        // } 

        // if(bchesapce==1 && rem==1)
        // {
        //     temp.insert(temp.begin(),remch);
        // }

        // for(auto it:temp){
        //     cout<<it<<" ";
        // }


        // for(int i=1;i<s.size();i++){
        //     if((temp[i]==temp[i-1]) || (temp[i]=='A'))
        //     return "";
        // }
        // string ans="";
        // for(int i=0;i<s.size();i++){
        //     ans+=temp[i];
        // }
        
    }
};