#include <iostream>
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
    // ek prev set krdiya jo curr se piche rhega
    Node *prevNode = NULL;

    // curr node set krdiya jo initially head pe set rhega
    Node *currNode = head;

    // loop tb tk chlega jb tk curr node null nahi ho jata
    while(currNode != NULL) {
        // ek temporary node bnayege jo curr node ke next ko track krke rkhega
        Node *nextNode = currNode -> next;

        // ab curr node ke pointer ko prev node pe point krwa denge
        // actual reverse ho jayega isse
        currNode -> next = prevNode;

        // ab prev node ko aage shift kr denge
        prevNode = currNode;

        // ab curr node ko aage shift krr denge
        currNode = nextNode;
    }

    // finally reversed linked list ka new head prev node hoga
    /// to prev node ko return krdenge
    return prevNode;
}

Node* calculateSum(Node *head1, Node *head2) {
    // agr head1 linked list null hai
    // means hmare paas 1st number hi nahi hai
    // to second number hi return krdenge
    if(head1 == NULL) {
        return head2;
    }

    // agr head2 linked list null hai
    // means hmare paas 2nd number hi nahi hai
    // to first number hi return krdenge
    if(head2 == NULL) {
        return head1;
    }



    // step 1 -> reverse both the linked lists
    head1 = reverseList(head1);
    head2 = reverseList(head2);



    // create two new pointers which points to new linked list head and tail
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    // take a carry variable
    int carry = 0;

    // run a loop if both linked list has matching lengths
    while(head1 != NULL and head2 != NULL) {
        // calculate the sum of both lists current node
        int sum = carry + head1 -> data + head2 -> data;

        // finding digit from the sum
        int digit = sum % 10;

        // find if there is any carry to pass on
        carry = sum / 10;

        // ab jo bhi digit nikal ke aayi hai
        // uski ek node create krlo
        Node *newNode = new Node(digit);

        // ab finalAns wali linked list me iss node ko add krdenge
        // agr finalHead null hai means final list abhi tk empty hai
        // to yahi hmari first node hogi
        if(finalHead == NULL) {
            finalHead = newNode;
            finalTail = newNode;
        }
        // agr finalHead null nahi hai
        // means ans list me already data hai
        // to newNode ko uske piche append krenge
        else {
            finalTail -> next = newNode;
            finalTail = newNode;
        }



        // ab dono linked lists ke heads ko aage shift krdenge
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    

    // agr head1 list jo hai wo head2 list se length me badi hai
    // to head1 list ko khaali krenge ab
    while(head1 != NULL) {
        int sum = carry + head1 -> data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);

        finalTail -> next = newNode;
        finalTail = newNode;

        head1 = head1 -> next;
    }




    // agr head2 list jo hai wo head1 list se length me badi hai
    // to head2 list ko khaali krenge ab
    while(head2 != NULL) {
        int sum = carry + head2 -> data;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);

        finalTail -> next = newNode;
        finalTail = newNode;

        head2 = head2 -> next;
    }



    // agr carry bhi end me bach gaya
    // to usko bhi linked list me adjust krdenge
    while(carry != 0) {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);

        finalTail -> next = newNode;
        finalTail = newNode;
    }



    // ab sb ho gaya to final jo linked list create hui hai usko bhi reverse krenge
    finalHead = reverseList(finalHead);

    // ab final list ko reverse krdenge
    return finalHead;
}

int main() {
    // creating first linked list, i.e., 1st number
    Node *one1 = new Node(2);
    Node *two1 = new Node(4);

    one1 -> next = two1;
    two1 -> next = NULL;

    Node *head1 = one1;

    // creating second linked list, i.e., 2nd number
    Node *one2 = new Node(2);
    Node *two2 = new Node(3);
    Node *three2 = new Node(4);

    one2 -> next = two2;
    two2 -> next = three2;
    three2 -> next = NULL;

    Node *head2 = one2;

    // printing first number, i.e., first linked list
    cout << "\nFirst Number: ";
    printList(head1);

    // printing second number, i.e., second linked list
    cout << "\nSecond Number: ";
    printList(head2);




    // calling function to calculate the sum of the both the above numbers
    Node *finalAns = calculateSum(head1, head2);

    // printing final sum
    cout << "\nSum of both the above numbers are: ";
    printList(finalAns);
    
    cout << endl;
    return 0;
}