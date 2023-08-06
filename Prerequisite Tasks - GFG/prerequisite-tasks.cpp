//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[V]; 
	    
	    for(auto &it:prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    
	  	   queue<int>q; 
	   vector<int> ind(V,0); 
	   
	   for(int i=0;i<V;i++){
	       for(auto &it:adj[i]){
	           ind[it]++;
	       }
	   }
	    
	    vector<int> ans; 
	    for(int i=0;i<V;i++){
	        if(ind[i]==0){
	            q.push(i);
	        }
	    }
	    
	    
	    while(!q.empty()){
	        
	        int node=q.front(); 
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto &it:adj[node]){
	            ind[it]--; 
	            if(ind[it]==0){
	                q.push(it); 
	            }
	        }
	    }
	    
	   if(ans.size()==V)
	   return true;
	   
	   return false;
	        
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends