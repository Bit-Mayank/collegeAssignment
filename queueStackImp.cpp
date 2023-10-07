#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> st;
    int capacity;
    int curr_size;

public:
    Queue(int n)
    {
        this->capacity = n;
        this->curr_size = 0;
    }

    void dequeue()
    {
        if (curr_size == 1)
        {
            st.pop();
            this->curr_size--;
            return;
        }
        int x = st.top();
        this->st.pop();
        this->curr_size--;
        dequeue();
        this->st.push(x);
        this->curr_size++;
    }

    void enqueue(int a)
    {
        this->st.push(a);
        curr_size++;
    }

    void display()
    {
        if (curr_size == 1)
        {
            cout << st.top() << " ";
            st.pop();
            this->curr_size--;
            return;
        }
        int x = st.top();
        this->st.pop();
        this->curr_size--;
        display();
        cout << x << " ";
        this->st.push(x);
        this->curr_size++;
    }
};

int main()
{
    Queue qu(10);
    for (int i = 0; i < 5; i++)
    {
        qu.enqueue(i);
    }
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(100);
    qu.display();
    cout << endl;
    return 0;
}