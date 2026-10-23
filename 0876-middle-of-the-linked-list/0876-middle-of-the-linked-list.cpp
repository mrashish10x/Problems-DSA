class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        for(int i=1;i<=len/2;i++){
            temp=temp->next;
        }
        return temp;
    }
};