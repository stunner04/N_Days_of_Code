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

Node *midElement(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main()
{
    Node *newNode = new Node(10);
    newNode->next = new Node(20);
    newNode->next->next = new Node(30);
    newNode->next->next->next = new Node(40);
    newNode->next->next->next->next = new Node(50);
    newNode->next->next->next->next->next = new Node(60);
    printSLL(newNode);

    cout << "Mid element is " << midElement(newNode)->data << "\n";
    return 0;
}