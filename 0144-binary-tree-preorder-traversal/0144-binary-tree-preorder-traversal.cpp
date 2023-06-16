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
    // vector<int> ans;
    // void dfs(TreeNode* root){
    //     if(root==NULL)
    //         return; 
    //     ans.push_back(root->val); 
    //     dfs(root->left); 
    //     dfs(root->right);
    // }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL)
//             return ans;
        
//         stack<TreeNode*> st; 
//         st.push(root); 
        
//         while(!st.empty()){
//             root=st.top(); 
//             st.pop();
//             ans.push_back(root->val);
//             if(root->right!=NULL)
//                 st.push(root->right);
//             if(root->left!=NULL)
//                 st.push(root->left);
            
//         } 
//         return ans;
//     }
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* tmp=st.top();
            st.pop();
            ans.push_back(tmp->val);
            if(tmp->right!=NULL)
            st.push(tmp->right);
            if(tmp->left!=NULL)
            st.push(tmp->left);
        }
        return ans;
    }

    
    
};