#include <iostream>
#include <limits.h>
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

class Stack
{
    int currSize;
    Node *head;
    int capacity;

public:
    Stack(int c)
    {
        this->capacity = c;
        this->head = nullptr;
        this->currSize = 0;
    }

    void push(int data)
    {
        if (this->currSize == this->capacity)
        {
            cout << "Overflow\n";
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->currSize++;
    }

    void pop()
    {
        if (this->head == nullptr)
        {
            cout << "Underflow\n";
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        temp->next = nullptr;
        free(temp);
    }

    int top()
    {
        if (this->head == nullptr)
        {
            cout << "Underflow\n";
            return INT_MIN;
        }
        return this->head->val;
    }
};

int main()
{
    Stack s(10);
    for (int i = 1; i <= 10; i++)
    {
        s.push(i);
    }

    for (int i = 1; i <= 10; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
