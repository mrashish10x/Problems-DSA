class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* ans = head->next;
        ListNode* a = head;
        ListNode* prev = NULL;

        while(a != NULL && a->next != NULL) {
            ListNode* b = a->next;
            ListNode* fwd = b->next;

            b->next = a;
            
            if(prev != NULL)
                prev->next = b;

            prev = a;
            a = fwd;
        }

        prev->next = a;

        return ans;
    }
};