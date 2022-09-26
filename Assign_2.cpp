/*
NAME - Vishesh Indora1
SID - 21105056
BRANCH - ECE
*/


// QUESTION 1
// While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element?

// SOLUTON - We can maintain a check that the varaible pointer , whenver it points to the adress same as that of the head node it must stop.
// now this logic has been implemented in this code.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput_circular_LL()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    // we would be using -1 value for data as an indication that only these mush nodes are to taken in the linked list.
    while (data != -1)
    {
        Node *newnode = new Node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    tail->next = head;
    return head;
}

// PRINTITNG A CIRCULAR LINKED LIST TILL ITS LAST NODE ONLY(AFTER THAT IT IS AGAIN HEAD).
void print_circular_LL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// HERE ALSO WE HAVE TO FIGURE OUT THE LAST ELEMENT USING THE SAME LOGIC, AND THEN ADD IT TO THE LAST.
void insert_at_tail(Node *&head, int k)
{
    if (head == NULL)
    {
        Node *newnode = new Node(k);
        head = newnode;
    }

    Node *newnode = new Node(k); // node to inserted at last has been created.

    // tail pointer to traverse to the last of the link list.
    Node *temp1 = head;
    Node *tail = head;
    tail = tail->next;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    // now the tail has reached the last of the node.

    // and now adding the newnode to the last and changing the links.
    tail->next = newnode;
    newnode->next = head;
}

// INSERTING THE NODE AT THE FRONT OF THE LINED LIST.
void insert_at_head(Node *&head, int k)
{
    if (head == NULL)
    {
        Node *newnode = new Node(k);
        head = newnode;
        return;
    }

    // node to be added at head is created.
    Node *newnode = new Node(k);

    // traversing to the tail to link it to the new head.
    Node *tail = head;

    while (tail->next != head)
    {
        tail = tail->next;
    }

    // adding the new node after the tail and then making it the head of the linked list.
    tail->next = newnode;
    newnode->next = head;
    head = newnode;
}

int main()
{
    // CREATING A LINKED LIST.
    Node *head = takeinput_circular_LL();
    print_circular_LL(head);
    cout << endl;

    // INSERTING ELEMENTS AT THE HEAD.
    insert_at_tail(head, 10);
    print_circular_LL(head);
    cout << endl;

    // INSERTING ELEMENTS AT THE TAIL.
    insert_at_head(head, 20);
    print_circular_LL(head);
}



/*
QUESTION -2
What are the practical applications of a circular linked list?
SOLUTION-
1. Used to manage the computing resources of a computer.
2. Other Data Structures such as Stacks, Queues can be implemented using the Circular Linked List.
3. Used in the implementation of heap.
4.They are also used for things like streaming video. The server sends us chunks of video and sound at kinda unpredictable rates - maybe every few seconds, another chunk of video appears that’s a second or so long, so we stuff it into a queue.
5. If your network connection is a bit slow - then it’s possible that the part that’s taking data out of the queue manages to empty it completely - and you have to display a “BUFFERING…” kind of message - such as you sometimes see if watching YouTube videos on a slow internet link.
*/