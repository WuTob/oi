#include <iostream>

using namespace std;

void quickSort(int *a, int l, int r);
void swap(int &a, int &b);

int main()
{
    int a[] = {1, 52, 63, 12, 2, 3};

    quickSort(a, 0, 5);

    for(int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
}

void quickSort(int *a, int l, int r)
{
    if(l > r) return;

    int stdNum = a[l];
    int lhs = l, rhs = r;

    while(lhs < rhs)
    {
        while(a[rhs] > stdNum && lhs < rhs) rhs--;
        while(a[lhs] < stdNum && lhs < rhs) lhs++;

        if(lhs != rhs) swap(a[lhs], a[rhs]);
    }


    quickSort(a, l, lhs - 1);
    quickSort(a, lhs + 1, r);
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}