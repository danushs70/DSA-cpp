#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &img,int row,int col,int original,int fill);
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        // If the starting pixel already has the target color
        if(original == color)
            return image;

        dfs(image, sr, sc, original, color);

        return image;
    }
void dfs(vector<vector<int>> &img,int row,int col,int original,int fill)
{
        
    int n = img.size(), m = img[0].size();
    if(row < 0 || col < 0 || row >= n || col >= m)
        return;

    if(img[row][col] != original)
        return;

    img[row][col] = fill;
        
    dfs(img, row + 1, col, original, fill);
    dfs(img, row - 1, col, original, fill);
    dfs(img, row, col + 1, original, fill);
    dfs(img, row, col - 1, original, fill);
}
void display(vector<vector<int>> img)
{
    for(int i=0;i<img.size();i++)
    {
        for(int j=0;j<img[i].size();j++)
        {
            cout<<img[i][j]<<", ";
        }
        cout<<endl;
    }
} 
int main()
{
    vector<vector<int>> img = {{1,1,1},{1,1,0},{1,0,1}};
    cout<<"before fill"<<endl;
    display(img);
    int sr = 1, sc = 1, color = 2;
    img = floodFill(img,sr,sc,color);
    cout<<"After fill"<<endl;
    display(img);

}