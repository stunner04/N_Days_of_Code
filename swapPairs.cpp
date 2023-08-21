#include <bits/stdc++.h>
using namespace std;

ListNode *swapPairs(ListNode *&head)
{

    if (head == NULL || head->next == NULL)
    { // base case
        return head;
    }
    
    ListNode *forw = NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;
    int count = 0;
    while (curr != NULL && count < 2)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
        count++;
    }

    if (forw != NULL)
    {
        head->next = swapPairs(forw);
    }
    return prev;
}

int main()
{
    return 0;
}