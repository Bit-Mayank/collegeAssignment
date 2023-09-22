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
        next = NULL;
    }
};

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = NULL;
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

    void deleteNodeAtArbitaryPos(int pos)
    {
        Node *temp = head;
        if (!pos)
        {
            head = temp->next;
            free(temp);
            return;
        }

        while (pos - 1)
        {
            temp = temp->next;
            pos--;
        }

        Node *fre = temp->next;
        temp->next = temp->next->next;
        free(fre);
    }
};

int main()
{
    linkedList ll;
    for (int i = 0; i <= 10; i++)
    {
        ll.insert(i);
    }

    ll.display();
    ll.deleteNodeAtArbitaryPos(1);
    ll.display();
    ll.deleteNodeAtArbitaryPos(0);
    ll.display();
    ll.deleteNodeAtArbitaryPos(5);
    ll.display();
    return 0;
}