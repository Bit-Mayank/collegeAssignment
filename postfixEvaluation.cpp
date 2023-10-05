#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

int postfixEva(string s)
{
    int size = s.size();
    if (size == 0)
        return INT_MIN;
    stack<int> st;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '+')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c = a + b;
            st.push(c);
        }
        else if (s[i] == '-')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c = b - a;
            st.push(c);
        }
        else if (s[i] == '*')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c = a * b;
            st.push(c);
        }
        else if (s[i] == '/')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (a != 0)
            {
                int c = b / a;
                st.push(c);
            }
        }
        else
        {
            st.push(s[i] - '0');
        }
    }

    return st.top();
}

int main()
{
    string s = "1267-+*";
    int ans = postfixEva(s);
    cout << ans << endl;
    return 0;
}