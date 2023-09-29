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

public:
    Node *head, *tail;
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

    void deleteNodeByAddr(Node *addr)
    {
        if (!(addr->prev))
        {
            head->next->prev = nullptr;
            head = head->next;
            free(addr);
            return;
        }
        Node *temp = addr->prev;
        Node *next = addr->next;

        temp->next = next;
        if (next == nullptr)
        {
            tail = temp;
            free(addr);
            return;
        }
        next->prev = temp;
        free(addr);
    }
};

int main()
{
    doublyLL ll;
    for (int i = 1; i <= 5; i++)
    {
        ll.insert(i);
    }

    ll.display();
    ll.deleteNodeByAddr(ll.tail->prev->prev);
    ll.display();
    ll.revPrint();
    return 0;
}