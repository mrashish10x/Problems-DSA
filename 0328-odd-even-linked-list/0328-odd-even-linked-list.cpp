class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);

        ListNode* temp = head;
        ListNode* temp1 = dummy1;
        ListNode* temp2 = dummy2;

        int idx = 1;

        while(temp != NULL) {

            ListNode* nextNode = temp->next;
            temp->next = NULL;

            if(idx % 2 == 1) {
                temp1->next = temp;
                temp1 = temp;
            }
            else {
                temp2->next = temp;
                temp2 = temp;
            }

            idx++;
            temp = nextNode;
        }

        temp1->next = dummy2->next;

        return dummy1->next;
    }
};