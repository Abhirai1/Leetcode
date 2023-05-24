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
            vector<int> level; 
                        
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front(); 
                q.pop(); 
                if(temp->left!=NULL)
                   q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                level.push_back(temp->val);
            }
            if(cnt&1){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            cnt++;
        }
        return ans;
    }
};