#include<iostream>
#include<vector>
using namespace std;
// here i use ncr formula
#include<iostream>
#include<vector>
using namespace std;

int getval(int n, int r)
{
    int res = 1;
    for(int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

vector<int> getRow(int rowIndex) 
{
    vector<int> row(rowIndex + 1);
    for(int i = 0; i <= rowIndex; i++)
    {
        row[i] = getval(rowIndex, i);
    }
    return row;
}

int main()
{
    int rowIndex = 3;
    vector<int> row = getRow(rowIndex);

    for(int e : row)
        cout << e << ", ";

    return 0;
}
