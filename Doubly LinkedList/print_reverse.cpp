#include <bits/stdc++.h>
using namespace std;
#define AS 200005
#define str string
#define ll long long int
#define tc ll tc;cin>>tc;while(tc--)
#define Y cout<<"YES"<<endl
#define N cout<<"NO"<<endl

class Node{

  public:
      int val;
      Node *prev;
      Node *next;

      Node(int val){
       this->val=val;
       this->prev=NULL;
       this->next=NULL;
      }
};

void printList(Node* tail){
   Node* temp=tail;
   cout<<"Doubly List Reverse: ";
   while(temp!=NULL){
       cout<<temp->val<<" ";
       temp=temp->prev;

   }
   cout<<endl;
}

void insertAtTail(Node* &head,Node* &tail,int val){
    Node* newNode=new Node(val);

    if(tail==NULL){
        head=newNode; 
        tail=newNode;
        return;
     }
     tail->next=newNode;
     newNode->prev=tail;
     tail=newNode;
}

int main() {
    Node* head=NULL;
    Node* tail=NULL;

    int pos,val;
   
   while(1){
      int val; cin>>val;
      if(val==-1){
         break;
      }
      insertAtTail(head,tail,val);
      
   }
    printList(tail);

    return 0;
}
