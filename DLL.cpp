#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
};

void printDLL(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int getlength(Node *&head)
{
    int length = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    return length;
}

Node *insertAtHeadDLL(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return head;
    }
    temp->next = head;
    head->previous = temp;
    head = temp;
}

Node *insertAtTailDLL(Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        return tail;
    }
    tail->next = temp;
    temp->previous = tail;
    tail = temp;
}

Node *insertAtAnyDLL(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHeadDLL(head, data);
        return head;
    }
    Node *curr = head;
    int count = 1;
    while (count < position - 1)
    {
        curr = curr->next;
        count++;
    }
    if (curr->next == NULL)
    {
        insertAtTailDLL(tail, data);
        return tail;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next->previous = temp;
    curr->next = temp;
    temp->previous = curr;
}

Node *deletionDLL(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    if (position == 1)
    {
        Node *curr = head;
        curr->next->previous = NULL;
        head = curr->next;
        curr->next = NULL;
        delete curr;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL) // tail deletion
        {
            tail = prev;
            prev->next = NULL;
            curr->previous = NULL;
            delete curr;
        }
        curr->next->previous = curr->previous; // mid deletion
        prev->next = curr->next;
        curr->previous = NULL;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *newNode = new Node(10);
    // newNode->next = new Node(20);

    // if NULL
    // Node *tail = NULL;
    // Node *head = NULL;

    Node *tail = newNode;
    Node *head = newNode;
    printDLL(head);
    cout << "Length of DLL is " << getlength(head) << "\n";

    // INSERTION DRIVER CODE
    insertAtHeadDLL(head, 55);
    insertAtHeadDLL(head, 99);
    printDLL(head);
    cout << "Length of DLL is " << getlength(head) << "\n";

    insertAtTailDLL(tail, 44);
    insertAtTailDLL(tail, 48);
    printDLL(head);
    cout << "Length of DLL is " << getlength(head) << "\n";

    insertAtAnyDLL(head, tail, 1, 88);
    printDLL(head);
    insertAtAnyDLL(head, tail, 4, 24);
    printDLL(head);
    insertAtAnyDLL(head, tail, 8, 40);
    printDLL(head);
    cout << "Length of DLL is " << getlength(head) << "\n";

    cout << "HeadPointsAt: " << head->data << " "
         << "TailsPointsAt: " << tail->data << "\n";

    // DELETION DRIVER CODE
    deletionDLL(head, tail, 3); // mid ele
    printDLL(head);
    cout << "HeadPointsAt: " << head->data << " "
         << "TailsPointsAt: " << tail->data << "\n";

    deletionDLL(head, tail, 1); // first ele
    printDLL(head);
    cout << "HeadPointsAt: " << head->data << " "
         << "TailsPointsAt: " << tail->data << "\n";

    deletionDLL(head, tail, 5); // last ele not working
    printDLL(head);
    cout << "HeadPointsAt: " << head->data << " "
         << "TailsPointsAt: " << tail->data << "\n";

    return 0;
}