#include <bits/stdc++.h>
using namespace std;
int main()
{
    int matrix[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> matrix[i][j];
    }

    int row = 0, col = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 1)
            {
                row = i + 1;
                col = j + 1;
                break;
            }
        }
    }

    cout << (abs(row - 3) + abs(col - 3)) << endl;
    return 0;
}