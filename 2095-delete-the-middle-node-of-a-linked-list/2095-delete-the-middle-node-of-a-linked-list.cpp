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
    ListNode* deleteMiddle(ListNode* head){ 
        ListNode *slow=head,*fast=head,*ptr=head;
        if(head==NULL || head->next==NULL){
            head=NULL;
            return head;
        }
        int cnt=0; 
        while(ptr!=NULL){
            cnt++;
            ptr=ptr->next;
        }
        cnt=(cnt/2)-1;
        while(cnt--){
            slow=slow->next;
        }
        slow->next=slow->next->next; 
        return head;
    }
};