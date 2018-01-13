#include <iostream>
using namespace std;

int main()
{
    struct POS{
        int x;
        int y;
    };

    POS soilder, horse, horseMove[9];
    cin >> soilder.x >> soilder.y >> horse.x >> horse.y;

    horseMove[0] = {horse.x + 1, horse.y + 2};

    return 0;
}