#include <iostream>
#include <limits.h>
using namespace std;

class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow\n";
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Underflow\n";
            return;
        }
        this->top--;
    }

    int getTop()
    {
        if (this->top == -1)
        {
            cout << "Underflow\n";
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty()
    {
        return this->top == -1;
    }
};

int main()
{
    Stack s(10);
    for (int i = 1; i <= 10; i++)
    {
        s.push(i);
    }

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}