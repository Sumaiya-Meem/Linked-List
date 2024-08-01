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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        while (tempA!=NULL) {
            lenA++;
            tempA = tempA->next;
        }
        
        while (tempB!=NULL) {
            lenB++;
            tempB = tempB->next;
        }
        
  
        tempA = headA;
        tempB = headB;
        if (lenA > lenB) {
            int diff = lenA - lenB;
            for (int i=0; i<diff; i++) {
                tempA = tempA->next;
            }
        } else {
            int diff = lenB - lenA;
            for (int i=0; i<diff; i++) {
                tempB = tempB->next;
            }
        }
        
        
        while (tempA!=NULL && tempB!=NULL) {
            if (tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;

        // Beats: 90%
    }
};
