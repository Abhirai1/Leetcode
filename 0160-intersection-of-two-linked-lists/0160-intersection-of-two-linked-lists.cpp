/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
         ListNode *l1=headA,*l2=headB; 
        
        while(l1!=l2){
            if(l1==NULL)
                l1=headB; 
            else
                l1=l1->next; 
            
            if(l2==NULL)
                l2=headA; 
            else
                l2=l2->next; 
            
            
        } 
        return l1;
        
        
        
//         int f=0; 
//         int s=0; 
//         ListNode *ptr1 = headA,*ptr2=headB;
//          ListNode *l1 = headA,*l2=headB;
//         while(ptr1!=NULL){
//             f++;
//             ptr1=ptr1->next;
//         }
//         while(ptr2!=NULL){
//             s++;
//             ptr2=ptr2->next;
//         } 
        
//         if(f>s){
//             int temp=f-s; 
//            l1 = headA;
//             l2=headB;
//             while(temp--){
//                 l1=l1->next;
//             } 
            
//             while(l1!=NULL){
//                 if(l1->val == l2->val){
//                     return l1;
//                 }
//                 l1=l1->next; 
//                 l2=l2->next;
//             }
//         }
//         else{
//             int temp=s-f; 
//              l1 = headA;l2=headB;
//             while(temp--){
//                 l2=l2->next;
//             } 
            
//             while(l2!=NULL){
//                 if(l1->val == l2->val){
//                     return l2;
//                 }
//                 l1=l1->next; 
//                 l2=l2->next;
//             }
//         } 
//         return l1;
    }
};