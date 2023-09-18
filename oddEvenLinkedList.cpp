#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void printLinkedList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

Node *oddEvenLinkedList(Node *head)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    Node *oddHead = new Node(-1);
    Node *oddTail = oddHead;

    Node *evenHead = new Node(-1);
    Node *evenTail = evenHead;

    Node *curr = head;
    int pos = 1;

    while (curr != nullptr)
    {
        if (pos % 2 == 1) // odd
        {
            oddTail->next = curr;
            oddTail = curr;
        }
        else // even
        {
            evenTail->next = curr;
            evenTail = curr;
        }
        curr = curr->next;
        pos++;
    }

    oddTail->next = nullptr;
    evenTail->next = nullptr;

    oddTail->next = evenHead->next;

    Node *newHead = oddHead->next;

    delete oddHead;
    delete evenHead;

    return newHead;
}

int main()
{
    // Create a sample linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    head = oddEvenLinkedList(head);

    std::cout << "Modified Linked List: ";
    printLinkedList(head);

    // Clean up memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

// https://www.codingninjas.com/studio/problems/odd-and-even-positioned-linked-list-nodes_1229404