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

Node* insertAtEnd(Node *head, int &data) {
    Node *newNode = new Node(data);
    newNode -> next = NULL;

    Node *temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = newNode;

    return head;
}

Node* insertAtPosition(Node *head, int &data) {
    Node *newNode = new Node(data);
    newNode -> next = NULL;

    int position;
    cout << "\nEnter the position at which you want to insert " << data << ": ";
    cin >> position;

    if(position == 0 || position == 1) {
        return insertAtBeginning(head, data);
    }

    int count = 1;
    Node *temp = head;
    while(count < position - 1) {
        temp = temp -> next;

        if(temp -> next == NULL) {
            return insertAtEnd(head, data);
        }

        count++;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

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

    int data;
    cout << "\nEnter the value for the node you want to insert in the beginning: ";
    cin >> data;

    Node *newList = insertAtPosition(head, data);

    cout << "\nYour new list after inserting " << data << " at the end is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}