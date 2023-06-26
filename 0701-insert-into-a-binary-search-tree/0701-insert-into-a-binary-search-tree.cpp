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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        
        if(root==NULL){ 
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        
        TreeNode *curr=root; 
        TreeNode *prev=curr;
        
        while(curr){
            
            if(curr->val > val){
                prev=curr; 
                curr=curr->left;
            }
            else{
                prev=curr; 
                curr=curr->right;
            }
        } 
        
        if(prev->val > val){
            TreeNode *temp= new TreeNode(val); 
            prev->left=temp;
        }
        else{
             TreeNode *temp= new TreeNode(val); 
              prev->right=temp;
        }
        
        
        return root;
        
    }
};