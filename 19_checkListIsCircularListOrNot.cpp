#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

bool checkCircularLinkedList(Node *head) {
    if(head == NULL) {
        return false;
    }

    Node *temp = head -> next;
    
    while(temp != NULL and temp != head) {
        temp = temp -> next;
    }

    if(temp == head) {
        return true;
    }

    return false;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = NULL;

    Node *head = one;

    bool isCircular = checkCircularLinkedList(head);

    if(isCircular) {
        cout << "\nLinked List is circular" << endl;
    }
    else {
        cout << "\nLinked List is not circular" << endl;
    }
    
    cout << endl;
    return 0;
}