#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void printSLL(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " ";
        curr = curr->next;
    }
    cout << "\n";
}

Node *reverseSLL(Node *&head)
{

    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next; // store the next
        curr->next = prev;    // cutting the link and point to previous
        prev = curr;          // moving previous to  current
        curr = forward;       // moving current to forward
    }

    return prev;
}

int main()
{

    Node *newNode = new Node(10);
    newNode->next = new Node(20);
    newNode->next->next = new Node(30);
    newNode->next->next->next = new Node(40);
    printSLL(newNode);

    Node *head = NULL;
    head = reverseSLL(newNode);
    printSLL(head);

    return 0;
}

