class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int sz;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    int get(int index) {
        if (index < 0 || index >= sz) {
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (sz == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        sz++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (sz == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > sz) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == sz) {
            addAtTail(val);
        } else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            sz++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz) {
            return;
        }
        if (index == 0) {
            Node* deleteNode = head;
            head = head->next;
            delete deleteNode;
            if (sz == 1) {
                tail = NULL;
            }
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            if (index == sz - 1) {
                tail = temp;
            }
            delete deleteNode;
        }
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
