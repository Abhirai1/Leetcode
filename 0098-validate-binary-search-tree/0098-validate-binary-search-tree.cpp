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
    
    bool check(TreeNode *root, long long  int left, long long  int right){
        
        if(root==NULL){
            return true;
        }
        if(root->val >=right || root->val<=left)
            return false;
        return check(root->left,left,root->val) 
            && check(root->right,root->val,right);
    }
    
    bool isValidBST(TreeNode* root) {
       long long int mini=  LONG_MIN;
       long long  int maxi=LONG_MAX;
        cout<<mini<<" "<<maxi<<endl;
        
        return check(root,mini,maxi);
        
    }
};