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
};

void printLL(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

bool detectLoop(Node *&head) // taking space O(N)
{
    Node *curr = head;
    map<Node *, bool> nodeVisited;
    while (curr != NULL)
    {
        if (nodeVisited[curr] == true)
        {
            cout << "Present at: " << curr->data;
            return true;
        }
        nodeVisited[curr] = true;
        curr = curr->next;
    }
    return false;
}

Node *detectFloydLoop(Node *&head)
/*After every iteration the distance between the slow and fast pointer decreases in anticlockwise
so that they meet together at one node which ensures that there is loop in the linked list */
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Present at: " << slow->data;
            return slow;
        }
    }
    return NULL;
}

Node *startNodeOfLoop(Node *&head)
/* the distance travel form slow to meetup point is same and their intersection gives the start of the loop
A+B=kC*/
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *meetPoint = detectFloydLoop(head);

    if (meetPoint == NULL) // if loop does not exist
    {
        return NULL;
    }
    
    Node *slow = head;
    while (slow != meetPoint)
    {
        slow = slow->next;
        meetPoint = meetPoint->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *startLoopPoint = startNodeOfLoop(head);
    
    if (startLoopPoint == NULL)
    { // IF NO loop return head
        return head;
    
    }
    Node *curr = startLoopPoint;
    while (curr->next != startLoopPoint)
    {
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

int main()
{
    Node *newNode = new Node(10);
    newNode->next = new Node(20);
    newNode->next->next = new Node(30);
    newNode->next->next->next = new Node(40);
    newNode->next->next->next->next = new Node(50);

    printLL(newNode);

    cout << "Loop detected: " << detectLoop(newNode) << "\n";
    cout << "Loop detected: " << detectFloydLoop(newNode) << "\n";
    cout << "Loop started at: " << (startNodeOfLoop(newNode)->data) << "\n";

    return 0;
}