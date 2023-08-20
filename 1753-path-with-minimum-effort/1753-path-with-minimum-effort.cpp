class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
               
       int n=heights.size(); 
       int m=heights[0].size(); 
       
       vector<vector<int>> dis(n,vector<int> (m,1e9));
       
    //   for(int i=0;i<n;i++){
    //       for(int j=0;j<m;j++){
    //           dis[i][j]=INT_MAX;
    //       }
    //   }
       
       dis[0][0]=0;
       
       
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
       
       pq.push({{0},{0,0}});
       
       int delrow[4]={1,0,0,-1};
       int delcol[4]={0,1,-1,0};
       
       while(!pq.empty()){
           
           int diff = pq.top().first; 
           int row=pq.top().second.first; 
           int col=pq.top().second.second; 
           pq.pop();
           
           for(int i=0;i<4;i++){
               
               int nrow=row+delrow[i]; 
               int ncol=col+delcol[i];
               
               if (row == n - 1 && col == m - 1)
                return diff;
               
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                   
                   int newdiff = abs(heights[nrow][ncol]-heights[row][col]);
                   newdiff=max(newdiff,diff);
                   
                   if(newdiff < dis[nrow][ncol]){
                       dis[nrow][ncol]=newdiff; 
                       pq.push({newdiff,{nrow,ncol}});
                   }
                   
               }
               
           }
       } 
       
       return 0;
    }
};