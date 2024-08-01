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


int len(Node* head){
   Node* temp=head;
   int sz=0;
   while(temp!=NULL){
       temp=temp->next;
       sz++;
   }
   return sz;
}

void printList(Node* head){
   Node* temp=head;
   cout<<"List is: ";
   while(temp!=NULL){
       cout<<temp->val<<" ";
       temp=temp->next;

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

void deleteAtHead(Node* &head,Node* &tail){
     Node* deleteNode=head;   
     head=head->next;
     if(head==NULL){
         tail=NULL;
         delete deleteNode;
         return;
     }
     head->prev=NULL;
     delete deleteNode;
}

void deleteAtTail(Node* &head,Node* &tail){
    Node* deleteNode=tail; 
    tail=tail->prev;
    if(tail==NULL){
         head=NULL;
         delete deleteNode;
         return;       
    }
    tail->next=NULL;
    delete deleteNode;
}

void deleteAtAnyPosition(Node* &head, Node* &tail,int pos){

         if(pos==1){
            deleteAtHead(head,tail);
            printList(head);
            return ;
         }
         else if(pos==len(head)){
                 deleteAtTail(head,tail);
                 printList(head); 
                 return;
         }
         else if(pos>len(head)){
            cout<<"Invalid Index"<<endl;
            return;
         }
         
         Node* temp=head;
         for(int i=1;i<pos-1;i++){
                  temp=temp->next;
         }
         Node* deleteNode=temp->next;


         temp->next=temp->next->next;
         temp->next->prev=temp;
         delete deleteNode;  
         printList(head); 
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
   printList(head);

    while(1){
        cin>>pos;
        if(pos == -1){break;}
        deleteAtAnyPosition(head,tail,pos);
        
    }

    
    


    return 0;
}
