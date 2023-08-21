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

Node<int> *solve(Node<int> *first, Node<int> *second)
{
    Node<int> *curr1 = first;
    Node<int> *curr2 = second;
    Node<int> *next1 = curr1->next;
    Node<int> *next2 = curr2->next;

    // for single node
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    while (curr2 != NULL && next1 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            // add node inbetween nodes
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // updating first and second list pointers respectively
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            //move the pointers of first list by 1
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}


Node<int> *mergeTwoSortedList(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}






int main()
{
    Node *newNode = new Node(1);
    newNode->next = new Node(2);
    newNode->next->next = new Node(1);
    newNode->next->next->next = new Node(2);
    newNode->next->next->next->next = new Node(0);
    return 0;
}