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

bool findLoop(Node *head) {
    if(head == NULL) {
        cout << "\nLinked List is empty" << endl;
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while(fast != NULL) {
        fast = fast -> next;

        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        if(slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);
    Node *six = new Node(60);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = NULL;
    // six -> next = four;

    Node *head = one;

    int ans = findLoop(head);

    if(ans) {
        cout << "\nLoop is present" << endl;
    }
    else {
        cout << "\nLoop is not present" << endl;
    }
    
    cout << endl;
    return 0;
}