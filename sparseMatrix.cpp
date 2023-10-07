#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int f(int i, int j)
{
    return (i * (i - 1) / 2 + j);
}

int main()
{
    int n;
    cout << "Input values for n:";
    cin >> n;
    vector<int> arr(pow(n, 2));

    cout << "Input Matrix:\n:";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if (a != 0)
                arr[f(i, j)] = a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << arr[f(i, j)] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
