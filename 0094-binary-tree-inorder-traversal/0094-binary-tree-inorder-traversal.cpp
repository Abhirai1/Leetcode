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
    //     dfs(root->left); 
    //      ans.push_back(root->val); 
    //     dfs(root->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
        stack<TreeNode*> st; 
        TreeNode *ptr=root; 
        
        
        while(1){
            if(ptr!=NULL){
                st.push(ptr); 
                ptr=ptr->left;
            }
            else{
                if(st.empty()==true)
                    break;
                ptr=st.top();
                st.pop(); 
                ans.push_back(ptr->val);
                ptr=ptr->right;
            }
        } 
        return ans;
        
         
        
        // dfs(root); 
        // return ans;
//         vector<int> ans;
//         if(root==NULL)
//             return ans;
        
//         stack<TreeNode*> st; 
//         st.push(root); 
        
//         while(!st.empty()){
//             root=st.top(); 
//             st.pop();
//             if(root->left!=NULL)
//                 st.push(root->left);
//             ans.push_back(root->val);
//             if(root->right!=NULL)
//                 st.push(root->right);
            
            
//         } 
//         return ans;
    }
};