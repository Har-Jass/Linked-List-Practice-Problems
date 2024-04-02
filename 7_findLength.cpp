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

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);
    Node *six = new Node(60);
    Node *seven = new Node(70);
    Node *eight = new Node(80);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = seven;
    seven -> next = eight;
    eight -> next = NULL;

    Node *head = one;

    cout << "\nYour current list is: ";
    printList(head);

    int length = findLength(head);

    cout << "\nLength of your linked list is: " << length;
    
    cout << endl;
    return 0;
}