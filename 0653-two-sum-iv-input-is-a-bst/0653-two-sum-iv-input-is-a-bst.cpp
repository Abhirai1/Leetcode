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
    
    void inorder(TreeNode *root,vector<int> &in){
        if(root==NULL)
            return;
        
        inorder(root->left,in); 
        in.push_back(root->val); 
        inorder(root->right,in);
    }
    
    
    
    bool findTarget(TreeNode* root, int target) {
        vector<int> nums;
        inorder(root,nums);
        
        bool kill=false;
        
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i]; 
            if(ans.find(temp)==ans.end()){
                ans[nums[i]]=i;
            } 
            else{
                kill=true;
                break;
            }
        } 
        
        return kill;
        
    }
};