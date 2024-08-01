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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        
        k=k%n;
        if(k==0){return head;}

        int step=n-k;
        ListNode*  l2=head;
        for(int i=1;i<step;i++){
            l2=l2->next;
        }

        ListNode* l1=l2->next;
        l2->next=NULL;

        ListNode* result=l1;

        while(l1->next!=NULL){
            l1=l1->next;
        }
        l1->next=head;
        return result;

        

    }
};