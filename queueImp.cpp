#include <iostream>
#include <limits.h>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int back;
    int curr_size;
    int capacity;

public:
    Queue(int n)
    {
        this->arr = new int[n];
        this->front = -1;
        this->back = -1;
        this->curr_size = 0;
        this->capacity = n;
    }

    void enqueue(int m)
    {
        if (front == -1)
        {
            this->front++;
            this->back++;
            this->arr[back] = m;
            this->curr_size++;
            return;
        }

        this->back++;
        this->back = this->back % capacity;
        if (this->back == this->front)
        {
            cout << "Queue is full\n";
            return;
        }
        this->arr[back] = m;
        this->curr_size++;
    }

    void dequeue()
    {
        if (this->curr_size == 0)
        {
            cout << "Queue is Empty\n";
            return;
        }
        this->front++;
        this->curr_size--;
    }

    int getFront()
    {
        if (curr_size == 0)
        {
            cout << "Queue is Empty\n";
            return INT_MIN;
        }

        return this->arr[this->front];
    }
};

int main()
{
    Queue q(10);
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i);
    }

    for (int i = 0; i < 5; i++)
    {
        int a = q.getFront();
        cout << a << " ";
        q.dequeue();
    }

    for (int i = 11; i <= 15; i++)
    {
        q.enqueue(i);
    }

    for (int i = 0; i < 5; i++)
    {
        int a = q.getFront();
        cout << a << " ";
        q.dequeue();
    }
    cout << endl;
    return 0;
}