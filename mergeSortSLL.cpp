/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

********************************************************************/

node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node *newHead = new node(-1);
    node *tail = newHead;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            tail->next = left;
            tail = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            tail = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        tail->next = left;
        tail = left;
        left = left->next;
    }

    while (right != NULL)
    {
        tail->next = right;
        tail = right;
        right = right->next;
    }
    newHead = newHead->next;
    return newHead;
    delete (newHead);
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *left = head;
    node *mid = findMid(head);
    node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node *mergedList = merge(left, right);
    return mergedList;
}
