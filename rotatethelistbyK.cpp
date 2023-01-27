#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
ListNode *Nthnode(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;
    ListNode *curr = head;
    for (int i = 0; i < n; i++)
    {
        curr = curr->next;
    }

    ListNode *slow = head;
    ListNode *fast = curr;

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
ListNode *rotateRight(ListNode *head, int k)
{
    int count = 0;
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (head != NULL)
    {
        count++;
        prev = head;
        head = head->next;
    }
    if (count != 0)
        k = k % count;
    // K+1 node from last
    ListNode *temp = Nthnode(curr, k + 1);
    if (temp == NULL)
        return NULL;
    if (temp->next == NULL)
    {
        return curr;
    }
    ListNode *nxt = temp->next;
    temp->next = NULL;
    prev->next = curr;
    return nxt;
}
ListNode *insert(ListNode *head, int value)
{
    ListNode *temp = new ListNode(value);
    ListNode *curr = head;
    if (head == NULL)
        return temp;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void printlist(ListNode *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
int main()
{

    ListNode *list = NULL;
    list = insert(list, 10);
    list = insert(list, 10);
    list = insert(list, 10);
    list = insert(list, 15);
    list = insert(list, 30);
    list = insert(list, 30);
    printlist(list);
    int k;
    cin >> k;
    list = rotateRight(list, k);
    cout << endl;
    printlist(list);

    return 0;
}