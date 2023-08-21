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

Node *sort012BruteForce(Node *&head)
{
    int c0 = 0, c1 = 0, c2 = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            c0++;
        }
        else if (curr->data == 1)
        {
            c1++;
        }
        else if (curr->data == 2)
        {
            c2++;
        }
    }

    curr = head;

    while (curr != NULL)
    {
        if (c0 != 0)
        {
            curr->data = 0;
            cout << curr->data;
            c0--;
        }
        else if (c1 != 0)
        {
            curr->data = 1;
            cout << curr->data;

            c1--;
        }
        else if (c2 != 0)
        {
            curr->data = 2;
            cout << curr->data;

            c2--;
        }
        curr = curr->next;
    }
    return head;
}

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{
    Node *newNode = new Node(1);
    newNode->next = new Node(2);
    newNode->next->next = new Node(1);
    newNode->next->next->next = new Node(2);
    newNode->next->next->next->next = new Node(0);
    printSLL(newNode);
    newNode = sortList(newNode);
    printSLL(newNode);
    return 0;
}

