#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constrcutor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printCLL(Node *tail)
{

    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteCLL(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is Empty";
    }
    else
    {
        Node *previous = tail;
        Node *curr = previous->next;
        while (curr->data != value)
        {
            previous = curr;
            curr = curr->next;
        }
        previous->next = curr->next;

        if (previous == curr) // if one node present
        {
            tail = NULL;
        }
        else if (tail == curr) // if >=two nodes
        {
            tail = previous;
        }
        curr->next = NULL;
        delete curr;
    }
}

Node *detectFloydLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "SLOW==FAST at: " << slow->data << "\n";
            return slow;
        }
    }
    return NULL;
}

Node *startNodeOfLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *meetPoint = detectFloydLoop(head);
    if (meetPoint == NULL) // if loop does not exist
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != meetPoint)
    {
        slow = slow->next;
        meetPoint = meetPoint->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *startLoopPoint = startNodeOfLoop(head);
    if (startLoopPoint == NULL)
    { // IF NO loop return head
        return head;
    }
    Node *curr = startLoopPoint;
    while (curr->next != startLoopPoint)
    {
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

void printSLL(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 7);
    printCLL(tail);
    insertNode(tail, 7, 9);
    printCLL(tail);
    insertNode(tail, 7, 6);
    printCLL(tail);
    insertNode(tail, 9, 10);
    printCLL(tail);
    insertNode(tail, 6, 4);
    printCLL(tail);
    // deleteCLL(tail, 7);
    // printCLL(tail);

    cout << "Loop detected: " << (detectFloydLoop(tail)->data) << "\n";
    cout << "Loop started at: " << (startNodeOfLoop(tail)->data) << "\n";
    Node *startofRemovedLL = removeLoop(tail);
    cout << "Removed Loop LL: " << (printSLL(startofRemovedLL)) << "\n";

    return 0;
}
