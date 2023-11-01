#include <iostream>
#include <limits.h>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int back;
    int capacity;

public:
    Queue(int size)
    {
        this->arr = new int[size];
        this->front = -1;
        this->back = -1;
        this->capacity = size;
    }

    void enqueue(int data)
    {
        if (this->back == this->capacity - 1)
        {
            cout << "Queue is full\n";
            return;
        }
        if (this->front == -1)
        {
            this->front++;
            this->back++;
            this->arr[front] = data;
            return;
        }

        this->back++;
        this->arr[back] = data;
    }

    void dequeue()
    {
        if (this->front == -1)
            return;
        if (front == back)
        {
            front = back = -1;
            return;
        }
        this->front++;
    }

    bool isEmpty()
    {
        return this->back == -1;
    }

    int getFront()
    {
        if (this->front == -1)
        {
            return INT_MIN;
        }
        return this->arr[this->front];
    }
};

int main()
{
    Queue qu(10);
    for (int i = 1; i <= 10; i++)
    {
        qu.enqueue(i);
    }

    while (!qu.isEmpty())
    {
        cout << qu.getFront() << " ";
        qu.dequeue();
    }
    return 0;
}