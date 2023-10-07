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
        TreeNode *z=new TreeNode(val); 
        TreeNode *y=NULL;
        TreeNode *ptr=root;
        while(ptr!=NULL){
            y=ptr; 
            if(ptr->val>z->val){
                ptr=ptr->left;
            }
            else{
                ptr=ptr->right;
            }
        }
        if(y==NULL)
        root=z;
        else  if(y->val>z->val){
            y->left=z;
        }
        else{
            y->right=z;
        }
        return root;
    }
};