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
   
    
//     int max(int &l,int &r){
//         if(l>=r)
//             return l;
//         return r;
//     }
    
//     int cal(TreeNode* root,int &ans){
//         if(root==NULL)
//             return 0; 
        
//         int l=cal(root->left,ans); 
//         int r=cal(root->right,ans); 
//         int temp = (l+r+root->val);
//         ans=max(ans,temp); 
        
//         return (root->val + max(l,r));
//     }
    
     int maxPathDown(TreeNode* root,int &ans){
         if(root==NULL)
             return 0;
         int l=max(0,maxPathDown(root->left,ans));
         int r=max(0,maxPathDown(root->right,ans));
         int temp = (l+r+root->val);
         ans=max(ans,temp); 
          return (root->val + max(l,r));
     }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathDown(root,ans); 
        return ans;
        
        // int ans=0;
        // if(root==NULL)
        //     return 0; 
        // if((root->left==NULL) && (root->right==NULL))
        //     ans=root->val;
        // else
        //     ans=0;
        // cal(root,ans); 
        // return ans;
    }
};