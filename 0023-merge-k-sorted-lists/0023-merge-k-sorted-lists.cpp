/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class cmp {
    
    public:
    bool  operator() (ListNode *a,ListNode *b){
        return  a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        
        ListNode *dummy=new ListNode(-1);
        ListNode *ptr=dummy;
        
        int n=l.size();
        
        for(int i=0;i<n;i++){
            if(l[i]!=NULL){
                pq.push(l[i]);
            }
        } 
        while(!pq.empty()){
            ListNode *temp = pq.top(); 
            ptr->next=temp; 
            ptr=temp; 
            pq.pop();
            if(temp->next!=NULL)
                pq.push(temp->next);
        } 
        return dummy->next;
    }
};