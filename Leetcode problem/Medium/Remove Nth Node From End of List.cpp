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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n==1){return NULL;}

        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }

        temp=head;
        ListNode* prevNode=NULL;
        
        int c=0;
        int target=cnt-n; 

        if (target == 0) { 
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        while (temp != NULL) {
            if (c == target) {
                prevNode->next = temp->next;
                delete temp;
                return head;
            }
            prevNode = temp;
            temp = temp->next;
            c++;
        }

        return head;

    }
};