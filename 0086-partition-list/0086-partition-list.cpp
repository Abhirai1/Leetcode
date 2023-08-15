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
    ListNode* partition(ListNode* head, int x) {
        vector<int> temp; 
        ListNode* ptr=head;
        while(ptr!=NULL){
            if(ptr->val<x){
                temp.push_back(ptr->val);
            }
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL){
            if(ptr->val>=x){
                temp.push_back(ptr->val);
            }
            ptr=ptr->next;
        }

          ListNode* nodeHead = new ListNode(-1); 
        ListNode* pt=nodeHead;

        for(int i=0;i<temp.size();i++){
            ListNode* node = new ListNode(temp[i]); 
            pt->next=node; 
            pt=pt->next;
        }

        return nodeHead->next;

    }
};