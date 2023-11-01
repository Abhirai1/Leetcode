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
    unordered_map<int,int> ump;
    void inorder(TreeNode* root){
        if(root==NULL) return; 

        inorder(root->left);
        ump[root->val]++;
        inorder(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans; 
        inorder(root);
        priority_queue<pair<int,int>> pq; 
        for(auto it:ump){
            pq.push({it.second,it.first});
        }
        int temp=-1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop(); 

            if(it.first<temp){
                break;
            }
            ans.push_back(it.second); 
            temp=it.first;
        }

        return ans;
    }
};