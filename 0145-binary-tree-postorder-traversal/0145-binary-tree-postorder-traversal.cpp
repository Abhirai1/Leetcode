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
    //     dfs(root->right);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> st;
       TreeNode *curr = root,*temp;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                    
                }else{
                    curr=temp;
                }
            }
        }
        
        
        
        
        
        
        
        
//         vector<int> ans; 
//         if(root==NULL)
//             return ans;
        
//         stack<TreeNode*> st1; 
//         stack<int> st2;
//         st1.push(root); 
//         while(st1.size()!=0){
//             TreeNode *temp=st1.top();
//             st2.push(temp->val);
//             st1.pop(); 
//             if(temp->left!=NULL)
//                 st1.push(temp->left);
//             if(temp->right!=NULL)
//                 st1.push(temp->right);
//         } 
        
//         while(!st2.empty()){
//             ans.push_back(st2.top()); 
//             st2.pop();
//         } 
         return ans;
    }
};