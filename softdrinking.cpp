#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    int ml = (arr[1] * arr[2]) / arr[6];
    int slice = arr[3] * arr[4];
    int gm = arr[5] / arr[7];

    ml /= arr[0];
    slice /= arr[0];
    gm /= arr[0];
    cout << min({ml, slice, gm}) << endl;
    return 0;
}