#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeNumber(int);

int main()
{
    int n;
    cin >> n;

    if(n <= 4){
        cout << "empty";
        return 0;
    }

    if(n >= 5){
        cout << 3 << " " << 5;
    }

    for(int i = 5; i <= n; i++)
    {
        if(i + 2 > n) break;

        if(isPrimeNumber(i) && isPrimeNumber(i + 2)){
            cout << endl << i << " " << i + 2;
        }
    }
}

bool isPrimeNumber(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0){
            return false;
        }
    }

    return true;
}
