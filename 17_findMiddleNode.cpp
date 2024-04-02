// // APPROACH 1 -> BASIC APPROACH
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

// int findLength(Node *head) {
//     int count = 0;

//     Node *temp = head;

//     while(temp != NULL) {
//         temp = temp -> next;
//         count++;
//     }

//     return count;
// }

// Node* findMiddle(Node *head) {
//     int length = findLength(head);
//     int midValue;
//     Node *temp = head;

//     // even length
//     if(length % 2 == 0) {
//         midValue = length / 2;
//     }
//     // odd length
//     else {
//         midValue = (length / 2) + 1;
//     }
    
//     while(midValue > 1) {
//         temp = temp -> next;
//         midValue--;
//     }

//     return temp;
// }

// int main() {
//     Node *one = new Node(10);
//     Node *two = new Node(20);
//     Node *three = new Node(30);
//     Node *four = new Node(40);
//     Node *five = new Node(50);
//     Node *six = new Node(60);
//     Node *seven = new Node(70);

//     one -> next = two;
//     two -> next = three;
//     three -> next = four;
//     four -> next = five;
//     five -> next = six;
//     six -> next = seven;
//     seven -> next = NULL;

//     Node *head = one;

//     cout << "\nCurrent list is: ";
//     printList(head);

//     Node *midNode = findMiddle(head);

//     cout << "\nMiddle Node in the above list is: " << midNode -> data;
    
//     cout << endl;
//     return 0;
// }


// APPROACH 2 -> OPTIMIZED APPROACH, i.e., TWO POINTER APPROACH
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

Node* findMiddle(Node *head) {
    // if there is no element present in the linked list
    if(head == NULL) {
        cout << "\nEmpty List" << endl;
        return head;
    }

    // if there is only one element present in the linked list
    if(head -> next == NULL) {
        return head;
    }

    // if linked list has more than one element
    // then we start using two pointer approach
    
    // make a slow pointer and set it on head
    Node *slow = head;

    // make a fast pointer and set it on head
    Node *fast = head;

    // jb tk fast and slow dono null tk nahi pahuch jate tb tk
    // while loop ko run krenge
    while(slow != NULL and fast != NULL) {
        // we move fast pointer generally 2 steps ahead
        // but first we try to move it only 1 step
        fast = fast -> next;

        // ab hum check krenge that agr fast ko 1 step aage krne se
        // fast null nahi hota to fast to 1 step or aage krr denge
        if(fast != NULL) {
            fast = fast -> next;

            // jb fast 1 step aage ho jayega
            // to slow ko 1 step aage krr denge
            slow = slow -> next;
        }
    }

    // finally hmara slow mid position pe betha hoga
    // to slow ko return krdenge
    return slow;
}

int main() {
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
    Node *five = new Node(50);
    Node *six = new Node(60);
    Node *seven = new Node(70);

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = seven;
    seven -> next = NULL;

    Node *head = one;

    cout << "\nCurrent list is: ";
    printList(head);

    Node *midNode = findMiddle(head);

    cout << "\nMiddle Node in the above list is: " << midNode -> data;
    
    cout << endl;
    return 0;
}