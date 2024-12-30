
#include <bits/stdc++.h>

using namespace std;
int limit = 100;
 void shortestpath( int v, vector<vector<int>>cost, int dist[], int n){
    for(int i=1; i<=n ; i++){
        dist[i]= cost[v][i];
    }
    vector<bool >S(n+1 , false);
    S[v]= true; dist[v]= 0;

    for(int i =2; i<=n-1; i++){
        int u =-1;
        for(int j =1; j<=n ; j++)
            if(!S[j] && (u==-1||dist[j]<dist[u]))
                u =j;
        S[u] = true;
        for(int w =1; w<=n; w++){
            if(!S[w] &&cost[u][w] != limit&&(dist[w]>dist[u]+cost[u][w])){
                dist[w] = dist[u]+cost[u][w];
            }
        }
    }
 }

 int main(){
    int n, v,e;
    cin>>n>>v>>e;
    vector<vector<int >>G(n+1, vector<int>(n+1));
    int dist[n+1];
     for(int i=1; i<=n; i++){
            for(int j= 1; j<=n; j++){
            if(i==j)G[i][j]=0;
            else G[i][j] =100;
            }}
    for(int i=1; i<=e; i++){
            int a,b,c;
            cin>>a>>b>>c;
            G[a][b]=c;
            G[b][a]=c;
    }
    shortestpath(1, G, dist, n);
    for(int i=1; i<=n ;i++)cout<<dist[i]<<" ";

 }

 /*
 7 1 13
 1 2 1
 1 3 3
 1 6 10
 2 3 1
 2 5 5
 2 4 7
 2 7 2
 3 4 9
 3 5 3
 4 7 12
 4 5 2
 4 6 1
 5 6 2


 */
