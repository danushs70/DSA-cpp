#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rotate_90_degree(vector<vector<int>> &matrix)
{
     int i,s=matrix.size();
     //cout<<"s: "<<s<<endl;
     //cout<<"m[0]: "<<matrix[0].size()<<endl;
        int j;
        for(i=0;i<s;i++)
        {
            for(j=0;j<matrix[i].size();j++)
            {
                if(j<=i)
                    swap(matrix[i][j],matrix[j][i]);
            }
        }
        //----------or----------
        /*
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
        }
    }
        */
        for(i=0;i<s;i++)
            reverse(matrix[i].begin(),matrix[i].end());
}
void rotate_90_degree_own_method(vector<vector<int>> &matrix)
{
    int i,j,s=matrix.size();
    vector<int> res;
    vector<vector<int>> ans;
    for(j=0;j<s;j++)
    {
        res.clear();
        for(i=s-1;i>=0;i--)
        {
            res.push_back(matrix[i][j]);
        
        }
        ans.push_back(res);
    }
    for(i=0;i<s;i++)
        for(j=0;j<s;j++)
            matrix[i][j] = ans[i][j];
    

}
int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate_90_degree_own_method(matrix);
    for(auto mat:matrix)
    {
        for(auto m:mat)
            cout<<m<<" ";
        cout<<endl;
    }
}

/*
You are given an n x n 2D matrix representing an image, rotate the image
 by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify
the input 2D matrix directly. DO NOT allocate another 2D matrix and
do the rotation.

example 1
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

example 2 
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/