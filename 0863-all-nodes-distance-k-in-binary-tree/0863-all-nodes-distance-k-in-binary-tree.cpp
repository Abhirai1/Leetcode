/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
   void makeParent(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*> &parent){
       
       queue<TreeNode*> q; 
       q.push(root); 
       
       while(!q.empty()){
                         
               TreeNode* temp=q.front(); 
               q.pop(); 
               
               if(temp->left){
                   
                   parent[temp->left]=temp;
                    q.push(temp->left); 
                   
               }
               if(temp->right){
                   
                   parent[temp->right]=temp;
                    q.push(temp->right); 
                   
               } 
       } 
   }
    
    
    
    
    void findPath(TreeNode* root,TreeNode* target,int k,vector<int> &ans){
        
        unordered_map<TreeNode*,TreeNode*> parent;
        
        makeParent(root,target,parent);
        
        int cnt=0; 
        
        queue<TreeNode*> q; 
        q.push(target);
        
         unordered_map<TreeNode*,bool> dekhliya;
        dekhliya[target]=true;
        
        while(!q.empty()){
            
            int n=q.size();
             if(cnt++==k){
                break;
            }
            
            for(int i=0;i<n;i++){ 
                
            TreeNode *temp=q.front(); 
            q.pop();
            
           
            
            if(temp->left &&  !dekhliya[temp->left]){
                q.push(temp->left);
                dekhliya[temp->left]=true;
            }
            
            if(temp->right &&  !dekhliya[temp->right]){
                q.push(temp->right);
                dekhliya[temp->right]=true;
            }
            
            if(parent[temp] &&  !dekhliya[parent[temp]]){
                q.push(parent[temp]);
                dekhliya[parent[temp]]=true;
            }
            
         
            }
            
        }
        
        
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        
    }
    
    
  
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans; 
        
        if(root==NULL)
            return ans;
        
        
        findPath(root,target,k,ans);
        return ans;
            
    }
};