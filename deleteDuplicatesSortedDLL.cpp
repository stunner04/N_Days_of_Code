/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *removeDuplicates(Node *head) // 1 2 3 3 3 3 or 1 2 3 3 3 4
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
    Node *next = NULL;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            if (curr->next->next == NULL) // 1 2 3 3 3 3
            {
                delete (curr->next);
                curr->next->prev = NULL;
                curr->next = NULL;
                break;
            }
            next = curr->next->next;
            curr->next->next = NULL;
            delete (curr->next);
            curr->next = next;

            next->prev->prev = NULL;
            next->prev = curr;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
