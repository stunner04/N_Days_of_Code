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

// Sorted list
Node *removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            Node *nextToNext = curr->next->next;
            Node *nodeToBeRemoved = curr->next;
            delete nodeToBeRemoved;
            curr->next = nextToNext;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

// Unsorted list 3 methods - bruteforce,hashmap,sort and apply sorted removal algo
Node *removeByBruteForce(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        Node *tempCurr = curr->next;
        while (tempCurr->next != NULL)
        {
            if (curr->data == tempCurr->data)
            {
                // delete the tempCurr->data
            }
            else
            {
                tempCurr = tempCurr->next;
            }
        }
        curr = curr->next;
    }
}

Node *removeByHashMap(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    map<Node *, bool> visitedNode;
    Node *curr = head;
    Node *previous = NULL;
    while (curr->next != NULL)
    {
        if (visitedNode[curr->data] != true)
        {
            visitedNode[curr->data] = true;
            previous = curr;
            curr = curr->next;
        }
        // removal of already true element
        previous = curr->next;
        Node *toBeRemoved = curr;
        delete toBeRemoved;
        curr = previous;
        previous->next = previous;

        return head;
    }
}

void mapremoveduplicates(Node *&head)
{
    if (head == NULL)
        return;

    map<int, bool> visited;
    Node *cur = head;

    while (cur->next != NULL)
    {
        visited[cur->data] = true;
        if (visited[cur->next->data] == true)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    printSLL(head);
}

int main()
{
    Node *newNode = new Node(30);
    newNode->next = new Node(10);
    newNode->next->next = new Node(60);
    newNode->next->next->next = new Node(30);
    newNode->next->next->next->next = new Node(50);
    printSLL(newNode);

    // Node *removed = removeByHashMap(newNode);
    // printSLL(removed);

    mapremoveduplicates(newNode);

    return 0;
}
