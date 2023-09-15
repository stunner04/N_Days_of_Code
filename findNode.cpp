#include <bits/stdc++.h>
/*

    Following is the node structure
    class ListNode{
        public:
        int data;
        ListNode* next;
    };

    ListNode* newListNode(int data){
        ListNode *temp = new ListNode;
            temp->data = data;
            temp->next = NULL;
            return temp;
    }

*/
ListNode *detectFloydLoop(ListNode *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
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
            // cout << "Present at: " << slow->data;
            return slow;
        }
    }
    return NULL;
}

ListNode *findNode(ListNode *head, int n)
{
    // if(n>pos)
    // {
    // 	return NULL;
    // }

    int count = 0;
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *meetPoint = detectFloydLoop(head);

    if (meetPoint == NULL) // if loop does not exist
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *curr = slow;
    while (slow != meetPoint)
    {
        slow = slow->next;
        count++;
        meetPoint = meetPoint->next;
    }

    int x = count - n;
    if (x < 0)
    {
        return NULL;
    }
    for (int i = 0; i < x; i++)
    {
        curr = curr->next;
    }
    return curr;
}

// https://www.codingninjas.com/studio/problems/find-node_920443