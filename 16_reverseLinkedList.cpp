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

Node* reverseList(Node *head) {
    // base case: if the list is empty or has only one element
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    // currNode ko head pe point krwa do
    Node *currNode = head;

    // prevNode ko null pe point krwa do
    Node *prevNode = NULL;

    // loop tbhi tk run krega jb tk "currNode != NULL"
    while(currNode != NULL) {
        // ek "temp" pointer variable me currNode ka next node store krr lenge
        // so that wo lost na ho jaye
        Node *temp = currNode -> next;

        // ab currNode ke pointer ko change krenge
        // usko prevNode pe point krwa denge so that wo reverse ho jaye
        currNode -> next = prevNode;

        // ab prevNode ko aage krdenge, further iterations ke liye
        prevNode = currNode;

        // ab currNode ko bhi aage krr denge further iterations ke liye
        // means currNode ko temp ke equal krdenge
        currNode = temp;
    }

    // finally ab hmari reversed linked list ka head store hoga prevNode me
    return prevNode;
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
    Node *nine = new Node(90);
    Node *ten = new Node(100);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = seven;
    seven -> next = eight;
    eight -> next = nine;
    nine -> next = ten;
    ten -> next = NULL;

    Node *head = one;

    cout << "\nYour current linked list is: ";
    printList(head);

    Node *newList = reverseList(head);

    cout << "\nYour new linked list after reverse is: ";
    printList(newList);
    
    cout << endl;
    return 0;
}