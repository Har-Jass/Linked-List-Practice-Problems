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
    cout << "\nEnter the data you want to insert at the end: ";
    cin >> data;

    Node *newList = insertAtEnd(head, data);

    cout << "\nYour new list after inserting " << data << " at the end is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}