class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
     int maxo = *max_element(candies.begin() , candies.end()); 
     vector<bool>a;
        
     for(int i=0;i<candies.size();i++){
         if(( candies[i]+extraCandies )>=maxo ){
            a.push_back(true);
         } 
         else{
            a.push_back(false);
         }
     }
        
     return a; 
        
    }
};