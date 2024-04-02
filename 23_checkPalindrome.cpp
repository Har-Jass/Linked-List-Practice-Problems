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
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

Node* findMiddleNode(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while(slow != NULL and fast != NULL) {
        fast = fast -> next;

        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
    }

    return slow;
}

Node* reverseList(Node *head) {
    Node *currNode = head;
    Node *prevNode = NULL;
    Node *nextNode = currNode -> next;

    while(currNode != NULL) {
        nextNode = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}

bool checkPalindrome(Node *head) {
    // base case
    if(head == NULL) {
        cout << "\nEmpty List" << endl;
        return false;
    }

    // check if there is only single node in linked list
    if(head -> next == NULL) {
        return true;
    }

    // main logic
    // step 1 -> find middle node
    Node *middleNode = findMiddleNode(head);

    // step 2 -> after finding middle node, 
    // we start reversing the list from middleNode -> next
    Node *headOfReverse = reverseList(middleNode -> next);
    middleNode -> next = headOfReverse;

    // step 3 -> start comparing first part of linked list with second part of linked list
    Node *temp1 = head;
    Node *temp2 = headOfReverse;

    while(temp2 != NULL) {
        if(temp1 -> data != temp2 -> data) {
            return false;
        }
        else {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }

    return true;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(30);
    Node *six = new Node(20);
    Node *seven = new Node(10);
    Node *eight = new Node(5);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = seven;
    seven -> next = eight;
    eight -> next = NULL;

    Node *head = one;

    cout << "\nGiven Linked List: ";
    printList(head);

    if(checkPalindrome(head)) {
        cout << "\nLinked List is Palindrome" << endl;
    }
    else {
        cout << "\nLinked List is not palindrome" << endl;
    }
    
    cout << endl;
    return 0;
}