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

void printList(Node *head) {
    // base case
    if(head == NULL) {
        cout << "\nNothing to print as list is empty" << endl;
        return;
    }

    // main logic
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

Node* removeDuplicates(Node *head) {
    // base case
    if(head == NULL) {
        cout << "\nNothing to print as list is empty" << endl;
        return NULL;
    }

    // main logic
    Node *temp = head;

    while(temp != NULL) {
        // step 1 -> check if temp ka next is null or not
        // and temp ka data is equal to temp 
        if((temp -> next != NULL) and (temp -> data == temp -> next -> data)) {
            // change the pointer of temp -> next to temp -> next -> next
            temp -> next = temp -> next -> next;
        }
        else {
            temp = temp -> next;
        }
    }

    return head;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(20);
    Node *four = new Node(30);
    Node *five = new Node(40);
    Node *six = new Node(40);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = NULL;

    Node *head = one;

    cout << "\nLinked list before removing duplicates: ";
    printList(head);

    Node *newList = removeDuplicates(head);

    cout << "\nLinked list after removing duplicates: ";
    printList(newList);

    cout << endl;
    return 0;
}