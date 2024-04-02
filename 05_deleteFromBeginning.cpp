#include <bits/stdc++.h>
using namespace std;

// Structure of Singly Linked List
class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void printList(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

Node* deleteFromBeginning(Node *head) {
    head = head -> next;
    return head;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;  
    
    Node *head = one;

    cout << "\nYour current list is: ";
    printList(head);

    Node *newList = deleteFromBeginning(head);

    cout << "\nYour new list after deleting an element from beginning is: ";
    printList(newList);

    cout << endl;
    return 0;
}