#include<iostream>
using namespace std;
#include<vector>
void set_zero(vector<vector<int>> &mat)
{
    vector<int> r,c;
    int i,j,n=mat[0].size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j] == 0)
            {
                r.push_back(i);
                c.push_back(j);
            }
        }
    }
    for(int row : r)
    {
        for(j=0;j<n;j++)
        {
            mat[row][j] = 0;
        }
    }
    for(int col : c)
        for(i=0;i<n;i++)
            mat[i][col] = 0;
}

int main()
{
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
    int i,j,n=mat[0].size();
     cout<<"Matrix before "<<n<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    set_zero(mat);
    cout<<"Matrix After set zero"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}