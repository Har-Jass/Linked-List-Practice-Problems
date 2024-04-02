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

int findLength(Node *head) {
    Node *temp = head;
    int len = 0;
    while(temp != NULL) {
        temp = temp -> next;
        len++;
    }
    return len;
}

Node* reverseInKGroups(Node *head, int &k) {
    // check if the list is already empty
    if(head == NULL) {
        cout << "\nList is empty";
        return head;
    }

    // is length of the list is less than 'k'
    // then it means k is invalid
    int len = findLength(head);
    if(k > len) {
        cout << "\nEnter the valid value for k";
        return head;
    }

    // STEP 1 - 
    // now we start reversing the first k node of the list
    // and rest of the part will handled by recursion
    Node *prevNode = NULL;
    Node *currNode = head;
    Node *temp = currNode -> next;

    // create a count variable which counts upto k
    int count = 0;

    // jb tk count ki value k se less than rhegi
    // tb tk loop run krega
    while(count < k) {
        temp = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = temp;
        
        count++;
    }

    // STEP 2 - 
    // upar wale step me hmne starting ki first k nodes ko reverse krdiya
    // baaki ka saara kaam recursion krr lega
    // agr temp node null nahi hai to aage ka kaam krenge wrna nahi krenge
    if(temp != NULL) {
        head -> next = reverseInKGroups(temp, k);
    }

    // STEP 3 - 
    // finally hmari reversed linked list ka head prevNode me stored hoga
    // to prevNode ko return krr denge
    return prevNode;
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

    Node *head = one;

    cout << "\nCurrent linked list is: ";
    printList(head);

    int k;

    cout << "\nIn how many groups you want to reverse the above linked list: ";
    cin >> k;

    Node *newList = reverseInKGroups(head, k);

    cout << "\nLinked list after reverse in " << k << " groups are: ";
    printList(newList);

    cout << endl;
    return 0;
}