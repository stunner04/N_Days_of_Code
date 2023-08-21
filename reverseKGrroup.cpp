#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverseInKGroups(Node *&head, int k)
{

    if (head == NULL || head->next == NULL)
    { // base case
        return head;
    }
    Node *forw = NULL;
    Node *prev = NULL;
    Node *curr = head;
    int count = 0;
    while (curr != NULL && count < k)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
        count++;
    }

    if (forw != NULL)
    {
        head->next = reverseInKGroups(forw, k);
    }
    return prev;
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
    Node *newNode = new Node(10);
    newNode->next = new Node(20);
    newNode->next->next = new Node(30);
    newNode->next->next->next = new Node(40);
    newNode->next->next->next->next = new Node(50);
    printSLL(newNode);
    int k;
    cin >> k;
    Node *head = NULL;
    head = reverseInKGroups(newNode, k);
    printSLL(head);

    return 0;
}