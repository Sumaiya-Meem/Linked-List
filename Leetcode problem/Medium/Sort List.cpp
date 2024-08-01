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

   ListNode* merge(ListNode* list1,ListNode* list2){
      ListNode temp(0);
      ListNode* current=&temp;

      while(list1!=NULL && list2!=NULL){
        if(list1->val < list2->val){
            current->next=list1;
            list1=list1->next;
        }
        else{
            current->next=list2;
            list2=list2->next;
        }
        current=current->next;
      }
      if(list1!=NULL){
        current->next=list1;
      }
      if(list2!=NULL){
        current->next=list2;
      }

      return temp.next;
   }

   ListNode* getMiddle(ListNode* head){
        if (head ==NULL|| head->next ==NULL) {
            return head;
        }

    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
    } 
    return slow; 
   }


    ListNode* sortList(ListNode* head) {
        if (head ==NULL|| head->next ==NULL) {
            return head;
        }

        ListNode* mid=getMiddle(head);
        ListNode* rightIndex=mid->next;
        mid->next=NULL;
        
        ListNode* left = sortList(head);
        ListNode* right =sortList(rightIndex);

       return merge(left,right);

    }
};