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
 int len(ListNode* head){
    ListNode*  temp=head;
   int sz=0;
   while(temp!=NULL){
       temp=temp->next;
       sz++;
   }
   return sz;
    }

    ListNode* deleteMiddle(ListNode* head) {
       
    if(head==NULL || head->next==NULL){
        return NULL;
    }
  
    int n=len(head);
    int mid=n/2;

    ListNode* temp= head;
    for(int i=0;i<mid-1;i++){
            temp=temp->next;
    }
    ListNode* deleteNode=temp->next;
    temp->next=temp->next->next;
    delete deleteNode;  

    return head;

    }
};