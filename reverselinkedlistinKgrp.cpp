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

Node *reverse(Node *head, int k)
{
    Node *curr = head;
    bool isfirstpass = true;
    Node *prevfirst = NULL;
    while (curr != NULL)
    {
        Node *first = curr;
        Node *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isfirstpass)
        {
            head = prev;
            isfirstpass = false;
        }
        else
        {
            prevfirst->next = prev;
        }
        prevfirst = first;
    }
    return head;
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
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insert(head, 60);
    head = insert(head, 70);
    head = insert(head, 80);
    printlist(head);
    cout << endl;
    head = reverse(head, 3);
    printlist(head);
    return 0;
}