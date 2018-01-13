#include <iostream>
#include <string>
#include <strstream>

using namespace std;

void quickSort(int *a, int l, int r);
void swap(int &a, int &b);

int main()
{
    int n; cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);


    //TODO: 使用scanf string to int
    strstream ss; string result; int lastNum = a[0], cnt = 1;
    ss << a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] != lastNum)
        {
            cnt++;
            ss << " " << a[i];
        }
    }

    ss >> result;
    cout << cnt << endl << result;

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