class Solution {
public:

    
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        return prev;
    }

    
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* a = head;
        ListNode* b = slow->next;

        slow->next = NULL;

        // Reverse Second Half
        b = reverseList(b);

        // Merge Alternatively
        ListNode* temp1 = a;
        ListNode* temp2 = b;

        while(temp2 != NULL) {

            ListNode* first = temp1->next;
            ListNode* second = temp2->next;

            temp1->next = temp2;
            temp2->next = first;

            temp1 = first;
            temp2 = second;
        }
    }
};