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

bool detectLoop(Node *head) {
    if(head == NULL) {
        cout << "\nLinked List is already empty" << endl;
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

Node* findStartingOfLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        if(slow == fast) {
            slow = head;
            break;
        }
    }

    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

void printList(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

void removeLoop(Node *head, Node *startingPoint) {
    Node *prevNode = startingPoint -> next;

    while(prevNode -> next -> data != startingPoint -> data) {
        prevNode = prevNode -> next;
    }

    prevNode -> next = NULL;

    cout << "\nLinked List after removing loop is: ";
    printList(head);
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
    // eight -> next = NULL;
    eight -> next = four;

    Node *head = one;

    bool ans = detectLoop(head);

    if(ans) {
        Node* startingPoint = findStartingOfLoop(head);
        removeLoop(head, startingPoint);
    }
    else {
        cout << "\nLoop Absent" << endl;
    }
    
    cout << endl;
    return 0;
}