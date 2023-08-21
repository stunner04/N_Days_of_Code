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

int getCount(Node *&head)
{
    int count = 0;
    Node *curr = head;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int getIntersectionOfLL(Node *&head1, Node *&head2)
{
    int count1 = getCount(head1), count2 = getCount(head2);
    int absoluteDiff = abs(count1 - count2);
    Node *curr1 = head1;
    Node *curr2 = head2;

    if (count1 > count2)
    {
        while (absoluteDiff > 0)
        {
            curr1 = curr1->next;
            absoluteDiff--;
        }
    }
    else
    {
        while (absoluteDiff > 0)
        {
            curr2 = curr2->next;
            absoluteDiff--;
        }
    }

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
        {
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int main()
{
    Node *newNode;
    Node *head1 = new Node(10);
    Node *head2 = new Node(3);

    newNode = new Node(6);
    head2->next = newNode;

    newNode = new Node(9);
    head2->next->next = newNode;

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    printSLL(head1);
    printSLL(head2);
    cout << "Intersection Point : " << getIntersectionOfLL(head1, head2);
    
    return 0;
}