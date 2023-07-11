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
    
    
    
    
    TreeNode *MakeTree(vector<int> &preorder){
        
//         base case -> likhenge
        
        if(preorder.size()==0){
            return NULL;
        }
        
        TreeNode *temp=new TreeNode(preorder[0]);
        int n=preorder.size(); 
        vector<int> left;
        vector<int> right;
        for(int i=1;i<n;i++){
            if(preorder[0]>preorder[i]){
                cout<<preorder[i]<<" "<<endl;
                left.push_back(preorder[i]);
            }
            else{
                cout<<"right"<<endl;
                 right.push_back(preorder[i]);
            }
        }
        
        
        
        temp->left=MakeTree(left);
        temp->right=MakeTree(right);
        
        return temp;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *ans=MakeTree(preorder);
        return ans;
        
        
    }
};