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
    int getDecimalValue(ListNode* head) {
        
        // -> mera method space lg rha esme 

        // ListNode *ptr=head; 
        // vector<int> ans; 
        // while(ptr!=NULL){
        //     ans.push_back(ptr->val); 
        //     ptr=ptr->next;
        // } 
        // reverse(ans.begin(),ans.end()); 
        // int n=ans.size()-1;
        // int power=(ans[0]*(pow(2,0)));
        // for(int i=1;i<ans.size();i++){
        //     power+=(ans[i]*(pow(2,i)));
        // }
        // return power;

        // -> optimise solution 

        int ans=0; 
        ListNode *ptr=head;
        while(ptr!=NULL){
            ans*=2; 
            ans+=ptr->val; 
            ptr=ptr->next;
        }
        return ans;
    }
};