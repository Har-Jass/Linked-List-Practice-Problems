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

Node* insertAtBeginning(Node *head, int &data) {
    Node *newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
    return head;
}

int main() {
    // creating nodes
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);

    // set the next pointers of each node
    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;

    Node *head = one;

    cout << "\nYour current list is: ";
    printList(head);

    int data;
    cout << "\nEnter the value for the node you want to insert in the beginning: ";
    cin >> data;

    Node *newList = insertAtBeginning(head, data);

    cout << "\nYour new list after inserting " << data << " at the beginning is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}