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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = NULL;
    ListNode *curr = head;
    if (!list1 && !list2)
    {
        return head;
    }
    while (list1 != NULL && list2 != NULL)
    {

        if (list1->val <= list2->val)
        {
            ListNode *temp = new ListNode(list1->val);
            if (head == NULL)
            {
                head = temp;
                list1 = list1->next;
                curr = head;
            }
            else
            {
                head->next = temp;
                head = head->next;
                list1 = list1->next;
            }
        }
        else
        {
            ListNode *temp = new ListNode(list2->val);
            if (head == NULL)
            {
                head = temp;
                list2 = list2->next;
                curr = head;
            }
            else
            {
                head->next = temp;
                head = head->next;
                list2 = list2->next;
            }
        }
    }
    while (list2 != NULL)
    {
        ListNode *temp = new ListNode(list2->val);
        if (head == NULL)
        {
            head = temp;
            list2 = list2->next;
            curr = head;
        }
        else
        {
            head->next = temp;
            head = head->next;
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        ListNode *temp = new ListNode(list1->val);
        if (head == NULL)
        {
            head = temp;
            list1 = list1->next;
            curr = head;
        }
        else
        {
            head->next = temp;
            head = head->next;
            list1 = list1->next;
        }
    }
    return curr;
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

    ListNode *list1 = NULL;
    ListNode *list2 = NULL;
    list1 = insert(list1, 10);
    list1 = insert(list1, 20);
    list1 = insert(list1, 30);
    list2 = insert(list2, 15);
    list2 = insert(list2, 25);
    list2 = insert(list2, 30);
    printlist(list1);
    cout << endl;
    printlist(list2);
    cout << endl;
    printlist(mergeTwoLists(list1, list2));

    return 0;
}