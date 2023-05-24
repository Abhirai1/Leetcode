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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans; 
         if(root==NULL)
            return ans; 
        
        queue<TreeNode*> q; 
        q.push(root);
        int cnt=0;
        while(!(q.empty())){
            
            int n=q.size(); 
            vector<int> level(n); 
            int k; 
            if(cnt&1)
                k=n-1; 
            else
                k=0;
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front(); 
                q.pop(); 
                if(temp->left!=NULL)
                   q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                // level.push_back(temp->val);
                
                if(cnt&1){
                    level[k--]=temp->val;
                }
                else{
                    level[k++]=temp->val;
                }
            }
            ans.push_back(level);
            cnt++;
        }
        return ans;
    }
};