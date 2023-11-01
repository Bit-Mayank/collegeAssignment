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
        this->val = data;
        this->next = nullptr;
    }
};

class Queue
{
    Node *tail;
    Node *head;
    int size;

public:
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (!(this->head))
        {
            this->head = newNode;
            this->tail = newNode;
            this->size++;
            return;
        }

        this->tail->next = newNode;
        this->tail = this->tail->next;
        this->size++;
    }

    void dequeue()
    {
        if (!(this->head))
            return;

        Node *temp = this->head;
        this->head = this->head->next;
        if (this->head == nullptr)
        {
            this->tail = nullptr;
        }
        this->size--;
        free(temp);
    }

    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    int front()
    {
        if (this->head == nullptr)
            return INT_MIN;

        return this->head->val;
    }
};

int main()
{
    Queue qu;
    for (int i = 1; i <= 1; i++)
    {
        qu.enqueue(i);
    }

    while (!qu.isEmpty())
    {
        cout << qu.front() << " ";
        qu.dequeue();
    }
    return 0;
}