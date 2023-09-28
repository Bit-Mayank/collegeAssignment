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

void addNodeAtEnd(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void addNodeAtArbitraryPos(Node *&head, int val, int pos)
{
    Node *new_node = new Node(val);
    if (pos == 0)
    {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node *temp = head;
    // int cur_pos = 0
    while (pos - 1)
    {
        temp = temp->next;
        pos--;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void addNodeByRef(Node *&head, Node *&addr, int v)
{
    Node *newNode = new Node(v);
    newNode->next = addr->next;
    addr->next = newNode;
}

void addNodeByVal(Node *head, int value, int v)
{
    while (head && head->val != value)
    {
        head = head->next;
    }

    if (head)
    {
        Node *newNode = new Node(v);
        newNode->next = head->next;
        head->next = newNode;
    }
}

int main()
{
    Node *ll = new Node(1);

    int arr[4] = {2, 3, 5, 6};

    for (int i = 0; i < 4; i++)
    {
        addNodeAtEnd(ll, arr[i]);
    }

    display(ll);

    addNodeAtArbitraryPos(ll, 4, 5);

    display(ll);
    return 0;
}