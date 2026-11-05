class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* i=head;
        ListNode* j=head;
        while(j!=NULL){
            if(i->val == j->val)  j=j->next;
            else{
                i->next=j;
                i=j;
            }
        }
        if(i!=NULL) i->next=NULL;
        return head;
    }
};