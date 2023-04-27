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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode *dummy=new ListNode(-1); 
        ListNode *h=dummy;
        
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            // carry=(l1->val + l2->val)/10;
            cout<<carry<<endl;
            int temp=(l1->val + l2->val+carry)%10; 
             carry=(l1->val + l2->val +carry)/10;
            ListNode *k=new ListNode(temp);
            dummy->next=k;
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
        } 
        while(l1!=NULL){
            int temp=(l1->val+carry)%10; 
             carry=(l1->val +carry)/10;
            ListNode *k=new ListNode(temp);
            dummy->next=k;
            dummy=dummy->next;
            l1=l1->next;
        }
         while(l2!=NULL){
             cout<<carry<<endl;
            int temp=(l2->val+carry)%10; 
            carry=(l2->val+carry)/10;
            ListNode *k=new ListNode(temp);
            dummy->next=k;
             dummy=dummy->next;
             l2=l2->next;
        } 
        if(carry>0){
            ListNode *k=new ListNode(carry);
            dummy->next=k;
        }
        return h->next;
    }
};