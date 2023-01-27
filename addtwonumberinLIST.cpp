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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *curr;
    int sum = 0;
    ListNode *temp = new ListNode(0);
    ListNode *ans = temp;
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode *store = new ListNode(sum);
        temp->next = store;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        sum = l1->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode *store = new ListNode(sum);
        temp->next = store;
        temp = temp->next;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        sum = l2->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode *store = new ListNode(sum);
        temp->next = store;
        temp = temp->next;
        l2 = l2->next;
    }
    if (carry != 0)
    {
        ListNode *ans = new ListNode(carry);
        temp->next = ans;
    }
    return ans->next;
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
    list1 = insert(list1, 1);
    list1 = insert(list1, 2);
    list1 = insert(list1, 3);
    list2 = insert(list2, 5);
    list2 = insert(list2, 6);
    list2 = insert(list2, 7);
    printlist(list1);
    cout << endl;
    printlist(list2);
    cout << endl;
    ListNode *result = addTwoNumbers(list1, list2);
    printlist(result);

    return 0;
}