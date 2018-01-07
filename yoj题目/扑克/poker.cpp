#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector< vector<int> > > poker;

    int n;
    cin >> n;

    poker.resize(n + 1);
    for(int i = 0; i <= n; i++)
    {
        poker[i].resize(n + 1);
        for(int j = 0; j <= n; j++)
        {
            poker[i][j].resize(n + 1);
        }
    }

    const int face = 0, _back = 1, removed = -1;

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int pos[4];
        for(int j = 0; j < 4; j++)
        {
            cin >> pos[j];
        }

        if(pos[0] == 1)
        {
            int state = poker[pos[1]][pos[2]][pos[3]];
            if(state == -1) continue;

            poker[pos[1]][pos[2]][pos[3]] = !state;
        }
        if(pos[0] == 2)
        {
            poker[pos[1]][pos[2]][pos[3]] = -1;
        }
    }

    int backed = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(poker[i][j][k] == 1) backed++;
            }
        }
    }

    cout << backed;

    return 0;
}
