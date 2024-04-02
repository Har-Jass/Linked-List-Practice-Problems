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
    int count = 0;

    Node *temp = head;

    while(temp != NULL) {
        temp = temp -> next;
        count++;
    }

    return count;
}

Node* deleteFromBeginning(Node *head) {
    head = head -> next;
    return head;
}

Node* deleteFromEnd(Node *head) {
    Node *temp = head;

    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = NULL;

    return head;
}

Node *deleteFromPosition(Node *head, int &position) {
    if(position <= 1) {
        return deleteFromBeginning(head);
    }

    int length = findLength(head);
    if(position >= length) {
        return deleteFromEnd(head);
    }

    Node *temp = head;

    int count = 1;
    while(count < position - 1) {
        temp = temp -> next;
        count++;
    }

    temp -> next = temp -> next -> next;

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

    int position;
    cout << "\nEnter the position from where you want to delete the node: ";
    cin >> position;

    Node *newList = deleteFromPosition(head, position);

    cout << "\nYour new list after deleting a node from " << position << " position is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}