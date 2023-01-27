#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void removeduplicate(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
            curr = curr->next;
    }
}
Node *insert(Node *head, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    return temp;
}
void printlist(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{

    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 30);
    printlist(head);
    cout << endl;
    removeduplicate(head);
    printlist(head);
    return 0;
}