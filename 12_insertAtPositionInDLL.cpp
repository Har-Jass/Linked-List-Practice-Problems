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

int findLength(Node *head) {
    Node *temp = head;

    int length = 0;

    while(temp != NULL) {
        temp = temp -> next;
        length++;
    }

    return length;
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

Node *insertAtEnd(Node *head, int &data) {
    Node *newNode = new Node(data);
    newNode -> next = NULL;
    
    Node *temp = head;

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp;

    return head;
}

Node* insertAtPosition(Node *head, int &data, int &position) {
    if(position <= 1) {
        return insertAtBeginning(head, data);
    }

    int length = findLength(head);
    if(position > length) {
        return insertAtEnd(head, data);
    }

    Node *newNode = new Node(data);
    Node *temp = head;

    int count = 1;
    while(count < position - 1) {
        temp = temp -> next;
        count++;
    }

    Node *prevNode = temp;
    Node *nextNode = temp -> next;
    Node *currNode = newNode;

    currNode -> next = nextNode;
    currNode -> prev = prevNode;

    prevNode -> next = currNode;
    nextNode -> prev = currNode;

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


    int data;
    cout << "\nEnter the value for the node you want to insert: ";
    cin >> data;

    int position;
    cout << "\nEnter the position where you want to insert " << data << ": ";
    cin >> position;

    Node *newList = insertAtPosition(head, data, position);

    cout << "\nYour new list after inserting " << data << " at the " << position << " position is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}