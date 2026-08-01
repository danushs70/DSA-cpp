#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void floyed_warshall(int n, vector<vector<int>> &dist, vector<vector<int>> &predsisor)
{
    int i,j,k;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF && 
                dist[i][j] > dist[i][k] + dist[k][j] )
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // Update predecessor
                    predsisor[i][j] = predsisor[k][j];
                }
            }
        }
    }
}

void print_path(vector<vector<int>> &predsisor,int i, int j)
{
    if(i == j)
    {
        cout<<i<<" -- ";
        return;
    }
    else if(predsisor[i][j] == -1)
    {
        cout<<"there is no path form i to j"<<endl;
    }
    else{
        print_path(predsisor,i,predsisor[i][j]);
        cout<<j<<" --- ";
    }
}
int main() {
    int n = 5;

    // D^0 matrix from your notes
    vector<vector<int>> dist = {
        {0,   3,   8,   INF, -4},
        {INF, 0,   INF, 1,    7},
        {INF, 4,   0,   INF, INF},
        {2,   INF, -5,  0,   INF},
        {INF, INF, INF, 6,    0}
    };

    // predecessor matrix (pi matrix)
    vector<vector<int>> predsisor(n, vector<int>(n, -1));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( i != j && predsisor[i][j] != INF)
            {
                predsisor[i][j] = i;
            }
        }
    }

    floyed_warshall(n,dist, predsisor);

     cout << "Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    int src = 0, dest = 3;
    cout<<"let see shotest path for src = "<<src<<", to dest = "<<dest<<" : ";
    print_path(predsisor, src, dest);
    cout<<endl;
}

/*
 
*/