#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            return;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
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

    void reverseLL()
    {
        if (!head || !(head->next))
            return;

        Node *temp = head->next;
        Node *curr = head;
        head->next = nullptr;
        while (temp)
        {
            Node *next = temp->next;
            temp->next = curr;
            curr = temp;
            temp = next;
        }

        head = curr;
    }
};

int main()
{
    linkedList ll;

    for (int i = 1; i <= 10; i++)
    {
        ll.insert(i);
    }
    ll.display();
    ll.reverseLL();
    ll.display();
    ll.reverseLL();
    ll.display();
    return 0;
}