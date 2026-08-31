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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstPos = -1, lastPos = -1, prevCriticalPos = -1;
        int minDist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;
        
        while (curr->next != nullptr) {
            bool isMax = curr->val > prev->val && curr->val > curr->next->val;
            bool isMin = curr->val < prev->val && curr->val < curr->next->val;
            
            if (isMax || isMin) {
                if (firstPos == -1) {
                    firstPos = pos;
                } else {
                    minDist = min(minDist, pos - prevCriticalPos);
                }
                lastPos = pos;
                prevCriticalPos = pos;
            }
            
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if (firstPos == -1 || firstPos == lastPos) {
            return {-1, -1};
        }
        
        int maxDist = lastPos - firstPos;
        return {minDist, maxDist};
    }
};