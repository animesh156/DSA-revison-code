#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// function to insert node at head

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

// function to insert node at tail
void insertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

// function to insert node at any position

void insertAtPosition(node* &head,node* &tail  int position, int data)
{
     // insert at head
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    
    
    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    
    // insert at last

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    node *insertNode = new node(data);

    insertNode->next = temp->next;

    temp->next = insertNode;
}

// function to print LL
void print(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(12);

    node *head = node1;
    node *tail = node1;

    print(head);

    insertAtTail(tail, 23);
    insertAtTail(tail, 33);

    print(head);

    insertAtPosition(head,tail, 3, 89);
    print(head);

    return 0;
}
