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
    
    int findHorizontalLength(TreeNode* root, vector<vector<long long int>> &ans){
       
        long long int  p=0;
        if(root==NULL)
            return p; 
        
        queue<pair<TreeNode*,long long int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            int n=q.size(); 
            long long int t = q.front().second;
            vector<long long int> level; 
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front().first;
               long long int k = q.front().second-t;
                q.pop(); 
                if(temp->left!=NULL)
                   q.push({temp->left,2*k});
                if(temp->right!=NULL)
                    q.push({temp->right,(2*k+1)});
                level.push_back(k);
            }
          long long int  s=level.size(); 
           long long int temp = (level[s-1]-level[0] + 1);
            if(temp>=p){
                p=temp;
            }
        }
        return p;
    }

    
    int widthOfBinaryTree(TreeNode* root) {
        
        vector<vector<long long int>> ans; 
        
       long long int t= findHorizontalLength(root,ans);
        return t;
       
    }
};