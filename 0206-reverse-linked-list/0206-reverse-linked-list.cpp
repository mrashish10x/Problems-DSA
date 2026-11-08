class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* fwd = curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
};