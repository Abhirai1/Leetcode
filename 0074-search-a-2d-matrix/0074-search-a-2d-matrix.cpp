class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0; 
        int e=(matrix.size()*matrix[0].size())-1;
        int mid; 
        while(s<=e){
            mid=s+(e-s)/2;
            int i = mid/(matrix[0].size()); 
            int j = mid-(i*matrix[0].size()); 
            if(matrix[i][j]==target)
            return true; 
            else if(matrix[i][j]>target)
            e=mid-1; 
            else 
            s=mid+1;
        }
        return false;

        
    }
};