class BrowserHistory {
public:

  class Node{

  public:
      string val;
      Node *prev;
      Node *next;

      Node(string val){
       this->val=val;
       this->prev=NULL;
       this->next=NULL;
      }
    };

    Node* temp=new Node(" ");

    BrowserHistory(string homepage) {
        temp->val=homepage;
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);

        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
    }
    
    string back(int steps) {
        for(int i=0;i<steps;i++){
            if(temp->prev!=NULL){
            temp=temp->prev;
        }
        }
        return temp->val;
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;i++){
        if(temp->next!=NULL){
            temp=temp->next;
        }
        }
        return temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */