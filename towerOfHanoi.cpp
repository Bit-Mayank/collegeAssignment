#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

void towerOfHanoi(int a, char A, char B, char C)
{
    if (a == 0)
        return;
    towerOfHanoi(a - 1, A, C, B);
    cout << A << "->" << B << endl;
    towerOfHanoi(a - 1, C, B, A);
}

int main()
{

    // int a = 3, b = 0, c = 0;
    // int cnt = 0;
    // towerOfHanoi(a, b, c, cnt);
    int n;
    cin >> n;

    // long long cnt;
    // cnt = pow(2, n) - 1;
    // cout << cnt << endl;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}