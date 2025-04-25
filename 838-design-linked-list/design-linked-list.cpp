class node {
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        node* temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (i == index) return temp->val;
            temp = temp->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        node* p = new node(val);
        p->next = head;
        head = p;
    }

    void addAtTail(int val) {
        node* p = new node(val);
        if (head == nullptr) {
            head = p;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = p;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        node* temp = head;
        int i = 0;
        while (temp != nullptr && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) return;

        node* p = new node(val);
        p->next = temp->next;
        temp->next = p;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr) return;

        if (index == 0) {
            node* d = head;
            head = head->next;
            delete d;
            return;
        }

        node* temp = head;
        int i = 0;
        while (temp->next != nullptr && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (temp->next == nullptr) return;

        node* d = temp->next;
        temp->next = temp->next->next;
        delete d;
    }
};
