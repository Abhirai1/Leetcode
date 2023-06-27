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
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> ans; 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode *temp = q.front(); 
            
            ans.push_back(temp->val);
            
            q.pop(); 
            
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        
        sort(ans.begin(),ans.end()); 
        
        return ans[k-1];
        
        
    }
};