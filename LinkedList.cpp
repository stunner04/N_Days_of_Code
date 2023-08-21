#include <bits/stdc++.h>
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

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Free Memory"
             << "\n";
    }
};

Node *insertAtHeadSLL(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node *insertAtTailSLL(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

Node *insertAtAnyPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHeadSLL(head, data);
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
        insertAtTailSLL(tail, data);
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
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

Node *deletionSLL(Node *&head, int position)
{
    if (position == 1)     // head deletion
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
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
        if (curr->next == NULL)
        /*
        while deleting if we delete the last node then tail points to an absurd location and
        tail->data will give error.
        */
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int searchSLL(Node *&head, int x)
{
    Node *curr = head;
    int position = 1;
    while (curr != NULL)
    {
        if ((curr->data) == x)
        {
            return position;
        }
        position++;
        curr = curr->next;
    }
    return -1;
}

int main()
{
    Node *newNode = new Node(10);
    Node *head = newNode;
    // newNode->next = new Node(20);
    // newNode->next->next = new Node(30);
    Node *tail = newNode;

    // printSLL(newNode);
    // insertAtHeadSLL(newNode, 40);
    // printSLL(newNode);

    // printSLL(head);
    // insertAtTailSLL(tail, 40);
    // printSLL(head);

    // printSLL(head);
    // insertAtAnyPosition(head, tail, 2, 40);
    // insertAtAnyPosition(head, tail, 3, 90);
    // insertAtAnyPosition(head, tail, 4, 70);
    // insertAtAnyPosition(head, tail, 5, -20);
    // printSLL(head);
    // insertAtAnyPosition(head, tail, 7, 24);
    // printSLL(head);
    // cout << head->data << " " << tail->data;

    // printSLL(head);
    // insertAtHeadSLL(head, 90);
    // insertAtHeadSLL(head, 60);
    // insertAtHeadSLL(head, 70);
    // insertAtHeadSLL(head, 80);
    // printSLL(head);

    // deletionSLL(head, 3); // mid ele
    // printSLL(head);

    // deletionSLL(head, 4); // last ele
    // printSLL(head);

    // deletionSLL(head, 1); // first ele
    // printSLL(head);

    insertAtHeadSLL(head, 30);
    insertAtHeadSLL(head, 60);
    insertAtHeadSLL(head, 70);
    insertAtHeadSLL(head, 90);
    printSLL(head);
    cout << searchSLL(head, 30);

    return 0;
}