#include <bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
typedef long long ll;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) // 1 - 2  - 3  - 4  - 5
    {
        if (head == NULL)
        {
            return NULL;
        }
        vector<int> v;
        ListNode *curr = head;
        while (curr != NULL)
        {
            v.push_back(curr->val); // 1   2   3   4   5
            curr = curr->next;
        }
        reverse(v.begin() + left - 1, v.begin() + right); // 1  4   3   2   5
        ListNode *temp = new ListNode(v[0]);
        head = temp;
        for (int i = 1; i < v.size(); i++)
        {
            ListNode *rootNode = new ListNode(v[i]);
            temp->next = rootNode;
            temp = rootNode;
        }
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode newNode = new ListNode(1);
    newNode->next = new ListNode(2);
    newNode->next->next = new ListNode(3);
    newNode->next->next->next = new ListNode(4);
    newNode->next->next->next->next = new ListNode(5);

    reverseBetween(&newNode, 2, 4);

    return 0;
}