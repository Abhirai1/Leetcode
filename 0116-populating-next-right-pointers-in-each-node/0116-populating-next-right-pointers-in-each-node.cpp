/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void levelTraverse(Node* root){
        queue<Node*> q; 
        vector<vector<Node*>> ans;
        q.push(root); 
        
        while(!q.empty()){
            vector<Node*> level;
            int n=q.size(); 
            for(int i=0;i<n;i++){
               Node* temp=q.front(); 
                q.pop(); 
                if(temp->left!=NULL)
                   q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                level.push_back(temp);
                
            } 
            ans.push_back(level);
        }
        
        for(auto &it:ans){
            int n=it.size(); 
            for(int i=0;i<n-1;i++){
                it[i]->next=it[i+1];
            }
            it[n-1]->next=NULL;
        }
        
}
    
    
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        levelTraverse(root);
        return root;
    }
};