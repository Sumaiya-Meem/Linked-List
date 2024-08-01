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
      Node *next;

      Node(int val){
       this->val=val;
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
   cout<<"List : ";
   while(temp!=NULL){
       cout<<temp->val<<" ";
       temp=temp->next;

   }
   cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail,int val){
     Node* newNode=new Node(val);
     if(head==NULL){
                  head=newNode;
                  tail=newNode;
                  return;
     }
     newNode->next=head;
     head=newNode;
}

void insertAtTail(Node* &head,Node* &tail,int val){
   Node* newNode=new Node(val);

    if(tail==NULL){
        head=newNode; 
        tail=newNode;
        return;
     }
   tail->next=newNode;
   tail=newNode;

}

void insertAtAnyPosition(Node* &head, Node* &tail,int pos,int val){
         Node* newNode=new Node(val); 

         if(pos==1){
            insertAtHead(head,tail,val);
            return ;
         }
         if(pos>len(head)+1){
            cout<<"Invalid Index"<<endl;
         }

         Node* temp=head;
         for(int i=1;i<pos-1;i++){
                  temp=temp->next;
         }
         newNode->next=temp->next;
         temp->next=newNode;   
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
        cin>>pos>>val;
        if(pos == -1 || val ==-1){break;}
        insertAtAnyPosition(head,tail,pos,val);
        printList(head);
    }

    
    


    return 0;
}
