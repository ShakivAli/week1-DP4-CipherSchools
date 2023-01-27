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
ListNode *mergeKLists(vector<ListNode *> &v)
{
    if (v.size() == 0)
    {
        return NULL;
    }
    else if (v.size() == 1)
    {
        return v[0];
    }
    else
    {
        int last = v.size() - 1;
        while (last > 0)
        {
            int i = 0, j = last;
            while (i < j)
            {
                v[i] = mergeTwoLists(v[i], v[j]);
                i++;
                j--;
                if (i >= j)
                {
                    last = j;
                }
            }
        }
        return v[0];
    }
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

    int n;
    cin >> n;
    vector<ListNode *> v(n);
    for (int i = 0; i < n; i++)
    {
        ListNode *list = NULL;
        list = insert(list, 10);
        list = insert(list, 20);
        list = insert(list, 30);
        list = insert(list, 40);
        v.push_back(list);
    }
    printlist(mergeKLists(v));

    return 0;
}