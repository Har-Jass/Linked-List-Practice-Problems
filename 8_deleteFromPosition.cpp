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

Node* deleteFromPosition(Node *head, int &position) {
    // agr user 1 ya usse niche ki koi position enter krta hai to hum first position se node delete krr denge
    if(position <= 1) {
        return deleteFromBeginning(head);
    }

    // finding the length of the given linked list
    int length = findLength(head);

    // agr user list ki length ya usse greater position enter krta hai to hum end position se node delete krr denge
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

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;

    Node *head = one;

    cout << "\nYour current list is: ";
    printList(head);

    int position;
    cout << "\nEnter the position from which you want to delete the node: ";
    cin >> position;

    Node *newList = deleteFromPosition(head, position);

    cout << "\nYour new list after deleting a node from " << position << " position is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}