class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *forward = NULL;
        while (curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                if (curr->next->next == NULL)
                {
                    delete (curr->next);
                    curr->next = NULL;
                    break;
                }
                forward = curr->next->next;
                curr->next->next = NULL;
                delete (curr->next);
                curr->next = forward;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};