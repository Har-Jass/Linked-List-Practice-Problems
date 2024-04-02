// /* Naive Approach, using Data Replacement */
// #include <bits/stdc++.h>
// using namespace std;

// class Node {
//     public:
//         int data;
//         Node *next;

//         Node(int data) {
//             this -> data = data;
//             this -> next = NULL;
//         }
// };

// void printList(Node *head) {
//     Node *temp = head;

//     while(temp != NULL) {
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }

//     cout << endl;
// }

// Node* sortList(Node *head) {
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     Node *temp = head;

//     while(temp != NULL) {
//         if(temp -> data == 0) {
//             zeroCount++;
//         }
//         else if(temp -> data == 1) {
//             oneCount++;
//         }
//         else {
//             twoCount++;
//         }

//         temp = temp -> next;
//     }

//     temp = head;

//     while(temp != NULL) {
//         while(zeroCount) {
//             temp -> data = 0;
//             zeroCount--;
//             temp = temp -> next;
//         }

//         while(oneCount) {
//             temp -> data = 1;
//             oneCount--;
//             temp = temp -> next;
//         }

//         while(twoCount) {
//             temp -> data = 2;
//             twoCount--;
//             temp = temp -> next;
//         }
//     }

//     return head;
// }

// int main() {
//     Node *one = new Node(1);
//     Node *two = new Node(0);
//     Node *three = new Node(1);
//     Node *four = new Node(1);
//     Node *five = new Node(2);
//     Node *six = new Node(0);

//     one -> next = two;
//     two -> next = three;
//     three -> next = four;
//     four -> next = five;
//     five -> next = six;
//     six -> next = NULL;

//     Node *head = one;

//     cout << "\nLinked List before sorting: ";
//     printList(head);

//     Node *newList = sortList(head);

//     cout << "\nLinked List after sorting: ";
//     printList(newList);
    
//     cout << endl;
//     return 0;
// }


/* Sort 0, 1 and 2 without data replacement */
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

Node* sortListWithoutDR(Node *head) {
    Node *temp = head;

    // creating heads for all the three dummy nodes
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    // creating tails for all the three dummy nodes
    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    while(temp != NULL) {
        if(temp -> data == 0) {
            // zeroTail -> next = temp;
            // zeroTail = zeroTail -> next;

            Node *zeroTemp = temp;
            temp = temp -> next;
            zeroTemp -> next = NULL;

            zeroTail -> next = zeroTemp;
            zeroTail = zeroTemp;
        }
        else if(temp -> data == 1) {
            // oneTail -> next = temp;
            // oneTail = oneTail -> next;

            Node *oneTemp = temp;
            temp = temp -> next;
            oneTemp -> next = NULL;

            oneTail -> next = oneTemp;
            oneTail = oneTemp;
        }
        else {
            // twoTail -> next = temp;
            // twoTail = twoTail -> next;

            Node *twoTemp = temp;
            temp = temp -> next;
            twoTemp -> next = NULL;

            twoTail -> next = twoTemp;
            twoTail = twoTemp;
        }
    }

    oneHead = oneHead -> next;
    twoHead = twoHead -> next;

    if(oneHead) {
        zeroTail -> next = oneHead;

        if(twoHead) {
            oneTail -> next = twoHead;
        }
    }
    else {
        if(twoHead) {
            zeroTail -> next = twoHead;
        }
    }

    zeroHead = zeroHead -> next;
    

    return zeroHead;
}

int main() {
    Node *one = new Node(1);
    Node *two = new Node(0);
    Node *three = new Node(1);
    Node *four = new Node(1);
    Node *five = new Node(2);
    Node *six = new Node(0);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = NULL;

    Node *head = one;

    cout << "\nLinked List before sorting: ";
    printList(head);

    Node *newList = sortListWithoutDR(head);

    cout << "\nLinked List after sorting: ";
    printList(newList);
    
    cout << endl;
    return 0;
}