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
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    while (head != NULL)
    {
        if (head->next != NULL && head->val == head->next->val)
        {
            while (head->next != NULL && head->val == head->next->val)
            {
                head = head->next;
            }
            prev->next = head->next;
            if (prev == dummy)
                dummy->next = head->next;
            head = head->next;
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
    return dummy->next;
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
    list = deleteDuplicates(list);
    cout << endl;
    printlist(list);

    return 0;
}