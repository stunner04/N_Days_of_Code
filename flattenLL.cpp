/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *down, Node *right)
{

    if (right == NULL)
    {
        return down;
    }

    Node *newHead = new Node(-1);
    Node *tail = newHead;
    while (down != NULL && right != NULL)
    {
        if (down->data < right->data)
        {
            tail->child = down;
            tail = down;
            down = down->child;
        }
        else
        {
            tail->child = right;
            tail = right;
            right = right->child;
        }
    }
    while (down != NULL)
    {
        tail->child = down;
        tail = down;
        down = down->child;
    }
    while (right != NULL)
    {
        tail->child = right;
        tail = right;
        right = right->child;
    }
    return newHead->child;
    delete (newHead);
}

Node *flattenLinkedList(Node *head)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *down = head;
    Node *right = flattenLinkedList(head->next);
    down->next = NULL;
    Node *newHead = merge(down, right);
    return newHead;
}
