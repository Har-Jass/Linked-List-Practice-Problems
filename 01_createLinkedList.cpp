#include <bits/stdc++.h>
using namespace std;

// Structure of Singly Linked List
// creating a node of a linked list
class Node {
    public:
        // data part of current node
        int data;

        // pointer part which points to next node
        Node *next;

        // parameterized constructor
        // it sets the node's data 
        // to the data passed by user as a parameter
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

// this function prints the actual linked list
void printList(Node *head) {
    cout << "\nLinked List is: ";

    // first we create the temp variable
    // this temp variable points to head, 
    // i.e., the very first node of our linked list
    Node *temp = head;

    // we run a while loop
    // and it runs until the temp variable becomes null
    while(temp != NULL) {
        // on every iteration we print the data of the list
        cout << temp -> data << " ";

        // after printing the data of current node
        // we increment the temp variable 
        // as it jumps to the next node
        temp = temp -> next;
    }
}

int main() {
    // creating nodes
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);

    // set the next pointers of the nodes
    // to the next node of linked list
    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;

    // always set the first node of the linked list as head node
    Node *head = one;

    // function to print the linked list
    printList(head);

    cout << endl;
    return 0;
}