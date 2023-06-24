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
    
    
        
    
    int preIndex=0;
    // int pass=0;
    
    TreeNode* makeTree(vector<int> &postorder,vector<int> &inorder,int is,int ie){  
    
        if(is>ie)
            return NULL; 
        
        
        TreeNode *root= new TreeNode(postorder[preIndex]); 
        preIndex++;
        
        int inIndex; 
        
        for(int i=is;i<ie;i++){
            if(inorder[i]==root->val){
                inIndex=i; 
                break;
            }
        }
        root->right=makeTree(postorder,inorder,inIndex+1,ie);
        root->left=makeTree(postorder,inorder,is,inIndex-1);
      
        
        return root;
        
        
    }
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        reverse(postorder.begin(),postorder.end());
        
        for(auto &it:postorder)
            cout<<it<<" ";
        
        TreeNode *ans= makeTree(postorder,inorder,0,inorder.size()-1);
            
        return ans;
        
    }
};