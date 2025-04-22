#include<bits/stdc++.h>
using namespace std;

const int INF=INT_MAX;


void floyed(vector<vector<int>> &g,int v){

vector<vector<int>>dist=g;


for(int k=0; k<v; k++)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(dist[i][k] !=INF && dist[k][j] !=INF && dist[i][k]+dist[k][j]<dist[i][j])
            {
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
}

for(int i=0; i<v; i++)
{
    for(int j=0; j<v; j++)
    {
        if(dist[i][j]==INF)
        {
            cout<<"INF";
        }
        else
        {
            cout<<dist[i][j]<<" ";
        }
    }
    cout<<endl;
}
}

int main()
{
    int v=5;
    vector<vector<int>>graph=
    {
        {
            0,3,8,INF,-4
        },
        {
            INF,0,INF,1,7
        },
        {
            INF,4, 0, INF,INF
        },
        {
            2,INF,-5, 0,INF
        },
        {
            INF,INF,INF,6,0
        }



    };


      floyed(graph,v);

    return 0;
}
