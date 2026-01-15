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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(!fast)return NULL;
        slow=head;

        while(slow!=fast){
            
            slow=slow->next;
            if(fast)fast=fast->next;
        }
        return slow;
        

        
    }
};