#include <bits/stdc++.h>
using namespace std;

// Structure of Doubly Linked List
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

Node* insertAtBeginning(Node *head, int &data) {
    // create a new node for the given data
    Node *newNode = new Node(data);

    // newNode ke prev ko null set krenge
    // coz wo first node hogi ab and 
    // first node ka prev always null hota hai
    newNode -> prev = NULL;

    // newNode abse first node hai
    // to uske next ko pehle ki first node se attach krdenge
    newNode -> next = head;

    // jo pehle ka head tha uske prev ko 
    // ab ki newNode se attach krdenge
    head -> prev = newNode;

    // head ko update krdenge
    head = newNode;

    // new head ko return krdenge
    return head;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);

    one -> prev = NULL;
    one -> next = two;

    two -> prev = one;
    two -> next = three;

    three -> prev = two;
    three -> next = four;

    four -> prev = three;
    four -> next = five;

    five -> prev = four;
    five -> next = NULL;

    Node *head = one;

    cout << "\nYour current linked list is: ";
    printList(head);

    int data;
    cout << "\nEnter the data you want to insert at the beginning: ";
    cin >> data;

    Node *newList = insertAtBeginning(head, data);

    cout << "\nYour new list after inserting " << data << " at the beginning is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}