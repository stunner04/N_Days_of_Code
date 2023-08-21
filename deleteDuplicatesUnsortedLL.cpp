#include <bits/stdc++.h>

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    map<int, bool> visited;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            Node *deletionNode = curr;
            if (prev->next->next == NULL)
            {
                prev->next = NULL;
                delete (deletionNode);
                break;
            }
            prev->next = curr->next;
            curr->next = NULL;
            curr = prev;
            delete (deletionNode);
        }
        visited[curr->data] = true;
        prev = curr;
        curr = curr->next;
    }
    return head;
}



// https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan&leftPanelTab=0