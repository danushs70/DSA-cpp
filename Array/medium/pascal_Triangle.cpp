#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numrows = 5;
    vector<vector<int>> arr(numrows);

    for (int i = 0; i < numrows; i++)
    {
        arr[i].resize(i + 1);

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}
