#include <bits/stdc++.h>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    Node *next1 = head->next;

    while (next1->next != NULL)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        if (curr->data == next1->data)
        {
            Node *toBeDeleted = next1;
            next1 = next1->next;
            curr->next = next1;
            delete toBeDeleted;
        }
        else
        {
            next1 = next1->next;
            curr = curr->next;
        }
    }

    // for last same elements like {....1 2 2 2} -> {....1 2}

    if (curr->data == next1->data && next1->next == NULL)
    {
        curr->next = NULL;
    }
    return head;
}

int main()
{
    // Create the linked list: 1 -> 2 -> 2 -> 2 -> 3 -> nullptr
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Call the removeDuplicates function
    head = removeDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    printLinkedList(head);

    // Clean up the memory (deallocate nodes)
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
