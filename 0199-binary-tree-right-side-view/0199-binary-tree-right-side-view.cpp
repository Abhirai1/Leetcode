/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
   void leftView(TreeNode *root,vector<int> &ans){
    
    // if(root==NULL)
    // return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        vector<int> temp; 
        int n=q.size();
        
        for(int i=0;i<n;i++){
            
            TreeNode *k=q.front();
            q.pop();
            temp.push_back(k->val);
            
            if(k->left!=NULL)
            q.push(k->left);
            if(k->right!=NULL)
            q.push(k->right);
            
        }
        
        int len=temp.size();
        ans.push_back(temp[len-1]);
    }
    
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
   
   if(root==NULL)
   return ans;
   

   leftView(root,ans);
   return ans;
    }
};