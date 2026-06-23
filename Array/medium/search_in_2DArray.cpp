#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    //get row size rs, get column size cs
    int rs=matrix.size(), cs= matrix[0].size();
    int i=0,j=cs-1;
    bool flag = false;
    while(i < rs)
    {
        if(target >= matrix[i][0] && target <= matrix[i][j])
        {
            for(int k=0;k<cs;k++)
            {
                if(matrix[i][k] == target)
                {
                    flag = true;
                    break;
                }
            }
        }
        i++;
    }
    return flag;
}
int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target= 9;
    if(searchMatrix(matrix,target))
        cout<<"Element found";
    else
    {
        cout<<"Element not found";
    }
}