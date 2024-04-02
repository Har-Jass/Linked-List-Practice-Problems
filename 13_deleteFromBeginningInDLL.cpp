#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node *prev;
        int data;
        Node *next;

        Node(int data) {
            this -> prev = NULL;
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
    Node *six = new Node(60);

    one -> prev = NULL;
    one -> next = two;

    two -> prev = one;
    two -> next = three;

    three -> prev = two;
    three -> next = four;

    four -> prev = three;
    four -> next = five;

    five -> prev - four;
    five -> next = six;

    six -> prev = five;
    six -> next = NULL;

    Node *head = one;

    cout << "\nYour current linked list is: ";
    printList(head);

    Node *newList = deleteFromBeginning(head);

    cout << "\nYour new list after deleting an element from beginning is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}