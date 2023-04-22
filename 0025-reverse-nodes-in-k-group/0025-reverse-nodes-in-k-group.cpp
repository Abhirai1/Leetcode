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
class Solution {
public:
    
//Function to reverse to link list
    
    void reverse(ListNode*s, ListNode*e){
        ListNode *p=NULL,*c=s,*n=s->next; 
        
        while(p!=e){
            c->next=p; 
            p=c; 
            c=n;
            if(n!=NULL)
            n=n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) 
            return head;
        ListNode *dummy = new ListNode(-1); 
        dummy->next=head; 
        ListNode *beforestart = dummy,*e=head; 
        
        int i=0; 
        while(e!=NULL){
            i++;
            if(i%k==0){
            //reverse krenge ynha pe window ban gyi hmari
                ListNode *s=beforestart->next,*temp=e->next; 
                reverse(s,e);  
                beforestart->next=e;
                s->next=temp; 
                beforestart=s; 
                e=temp;
                
            } 
            else{
                e=e->next;
            }
        } 
        return dummy->next;
        
    }
};