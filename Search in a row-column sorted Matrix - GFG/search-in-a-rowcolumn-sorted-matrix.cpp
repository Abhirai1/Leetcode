//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        int row=-1;
        for(int i=0;i<n;i++){
            
            
            if(matrix[i][0]<=x &&  matrix[i][m-1]>=x){
                row=i;
                for(int j=0;j<m;j++){
                    if(matrix[row][j]==x){
                        return true;
                    }
                }
             }
            
            
        }
        
        if(row==-1)
        return false;
        
        
        
        
        return false;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends