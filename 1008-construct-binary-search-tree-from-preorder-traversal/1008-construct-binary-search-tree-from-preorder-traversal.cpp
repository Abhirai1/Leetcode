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
    
        
    int preIndex=0;
    
    TreeNode* makeTree(vector<int> &postorder,vector<int> &inorder,int is,int ie){  
    
        if(is>ie)
            return NULL; 
        
        TreeNode *root= new TreeNode(postorder[preIndex]); 
        preIndex++;
        
        int inIndex; 
        
        for(int i=is;i<ie;i++){
            if(inorder[i]==root->val){
                inIndex=i; 
                break;
            }
        }
        
        root->left=makeTree(postorder,inorder,is,inIndex-1);
        root->right=makeTree(postorder,inorder,inIndex+1,ie);
        
        return root;
        
        
    }
    
    
//     TreeNode *MakeTree(preorder){
        
// //         base case -> likhenge
        
//         if(preorder.size()==0){
//             return NULL;
//         }
        
        
//         int n=preorder.size(); 
//         vector<int> left;
//         vector<int> right;
//         for(int i=1;i<n;i++){
//             if(preorder[0]<preorder[i]){
//                 left.push_back(preorder[i]);
//             }
//             else{
//                  right.push_back(preorder[i]);
//             }
//         }
        
//         TreeNode *temp=new Node(preorder[0]);
//          temp->left=MakeTree(left);
//         temp->right=MakeTree(right);
        
//     }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        // if(root==NULL)
        //     return root; 
        
        
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        
        // MakeTree(preorder);
         TreeNode *ans= makeTree(preorder,inorder,0,inorder.size()-1);
        return ans;
        
        
    }
};