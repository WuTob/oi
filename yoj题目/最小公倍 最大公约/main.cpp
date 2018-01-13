#include <iostream>

using namespace std;
void swap(int &, int &);

int main()
{
    int m , n;

    cin >> m >> n;
    if(m < n) swap(m, n);

    int lhs = m, rhs = n, result[2] = {};
    for(int r = lhs % rhs; r >= 0;)
    {
        if(r == 0) break;

        lhs = rhs; rhs = r; r = lhs % rhs;
    }

    result[0] = rhs;

    cout << rhs;
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}