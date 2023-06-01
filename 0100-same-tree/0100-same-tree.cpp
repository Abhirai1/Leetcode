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
    void preorder(TreeNode *p,vector<int> &ans){
        if(p==NULL){
             ans.push_back(100000);
            return;
        }
            ans.push_back(p->val);  
         preorder(p->left,ans);
         preorder(p->right,ans);
            
    }
    void inorder(TreeNode *p,vector<int> &ans){
        if(p==NULL){
             ans.push_back(100000);
            return;
        }
            
         inorder(p->left,ans);
         ans.push_back(p->val);
         inorder(p->right,ans);
            
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
            vector<int> p1; 
            vector<int> q1; 
        
            vector<int> p2; 
            vector<int> q2; 
            
            // if(p==NULL && q==NULL)
            //     return true; 
            
            inorder(p,p1);
            inorder(q,q1);
        
            preorder(p,p2);
            preorder(q,q2);
        
        if(p1==q1 && p2==q2)
        return true;
        
        return false;
        
    }
};