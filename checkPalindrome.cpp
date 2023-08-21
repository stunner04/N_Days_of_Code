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

bool isPalindrome(Node *&head)
{

    if (head == NULL && head->next == NULL)
    {
        return true;
    }
    Node *midEle = midElement(head);

    Node *temp = midEle->next;
    midEle->next = reverseSLL(temp);

    Node *head1 = head;
    Node *head2 = midEle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

Node *reorderList(Node *&head)
{
    Node *curr = head;
    Node *last = head;
    Node *storeCurrNext = NULL;
    while (last->next != NULL)
    {
        last = last->next;
    }

    while (curr != last)
    {
        storeCurrNext = curr->next;
        curr->next = last;
        curr = storeCurrNext;
        last->next = storeCurrNext;
        // if (curr->next->next == NULL)
        // {
        //     curr = last;
        //     last->next = NULL;
        // }
        curr->next->next = last;
        last->next = NULL;
    }

    return head;
}

int main()
{
    Node *newNode = new Node(1);
    newNode->next = new Node(2);
    newNode->next->next = new Node(3);
    newNode->next->next->next = new Node(3);
    newNode->next->next->next->next = new Node(9);
    newNode->next->next->next->next->next = new Node(1);

    printSLL(newNode);
    cout << "Is Palindrome: " << isPalindrome(newNode);
    // newNode = reorderList(newNode);
    // printSLL(newNode);
    return 0;
}