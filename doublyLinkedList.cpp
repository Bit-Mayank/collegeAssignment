#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int data)
    {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

class doublyLL
{
    Node *head, *tail;

public:
    doublyLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->next)
                cout << temp->val << "<->";
            else
                cout << temp->val;
            temp = temp->next;
        }
        cout << endl;
    }

    void revPrint()
    {
        Node *temp = tail;
        while (temp)
        {
            if (temp->prev)
                cout << temp->val << "<->";
            else
                cout << temp->val;
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    doublyLL ll;
    for (int i = 1; i <= 2; i++)
    {
        ll.insert(i);
    }

    ll.display();
    ll.revPrint();
    return 0;
}