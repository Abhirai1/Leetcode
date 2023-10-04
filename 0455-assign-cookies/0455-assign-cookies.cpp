class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         priority_queue<int, vector<int>, greater<int> > g1;
          priority_queue<int, vector<int>, greater<int> > s1;
      for(auto it:g){
          g1.push(it);
      } 
      for(auto it:s){
          s1.push(it);
      }
      int cnt=0;
        while(!g1.empty() && !s1.empty()){
            if(g1.top()<=s1.top()){
                cnt++;
                g1.pop();
                s1.pop();
            }
           else if(g1.top()>s1.top()){
               s1.pop();
            }
            else{
                g1.pop();
            }
        }
        return cnt;
    }
};