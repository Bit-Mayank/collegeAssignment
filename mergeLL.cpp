#include <iostream>
using namespace std;

struct Node
{

    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

struct linkedList
{

    Node *head;

    linkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

Node *merge(Node *&head1, Node *&head2)
{
    Node *dummyNode = new Node(-1);
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *ptr3 = dummyNode;
    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if (ptr1)
    {
        ptr3->next = ptr1;
    }
    else
    {
        ptr3->next = ptr2;
    }

    return dummyNode->next;
}

int main()
{
    linkedList ll1, ll2;
    for (int i = 0; i < 10; i++)
    {
        ll1.insert(i);
    }

    for (int i = 1; i < 5; i++)
    {
        ll2.insert(i);
    }

    ll1.display();
    ll2.display();

    ll1.head = merge(ll1.head, ll2.head);
    ll1.display();

    return 0;
}