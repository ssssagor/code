#include <bits/stdc++.h>
using namespace std;
const int n=11;
const int ROWS = 20;
const int COLS = 4;
int E[ROWS][COLS]={
{0,0,0,0},
{0,3,1,2},
{0,4,1,5},
{0,4,1,4},
{0,10,2,3},
{0,3,2,6},
{0,2,2,5},
{0,1,3,7},
{0,6,3,6},
{0,5,4,5},
{0,6,4,8},
{0,11,5,6},
{0,1,5,9},
{0,2,5,8},
{0,2,6,7},
{0,11,6,10},
{0,3,6,9},
{0,8,7,10},
{0,4,8,9},
{0,7,9,10}
};
int Cost[n][n]={
{0,0,0,0,0,0,0,0,0,0,0},
{0,1000,3,1000,4,4,1000,1000,1000,1000,1000},
{0,3,1000,10,1000,2,3,1000,1000,1000,1000},
{0,1000,10,1000,1000,1000,6,1,1000,1000,1000},
{0,4,1000,1000,1000,5,1000,1000,6,1000,1000},
{0,4,2,1000,5,1000,11,1000,2,1,1000},
{0,1000,3,6,1000,11,1000,2,1000,3,11},
{0,1000,1000,1,1000,1000,2,1000,1000,1000,8},
{0,1000,1000,1000,6,2,1000,1000,1000,4,1000},
{0,1000,1000,1000,1000,1,3,1000,4,1000,7},
{0,1000,1000,1000,1000,1000,11,8,1000,7,1000}
};


int t[n][3];
int near[n];

int Prims()
{
    int minCost=100;
    int index=0;
    int k=0;
    int l=0;

    for(int i=1;i<n;i++)
    {
       if(E[i][1]<minCost)
       {
         index=i;
         minCost=E[i][1];
       }
    }

    k=E[index][2];
    l=E[index][3];

    minCost=Cost[k][l];

    t[1][1]=k; t[1][2]=l;

    for(int i=1;i<n;i++)
    {
       if(Cost[i][l]<Cost[i][k])
         near[i]=l;
       else
         near[i]=k;
    }
    near[k]=0;near[l]=0;

    int j=0;

    for(int i=2;i<n-1;i++)
    {
        int mm=100;
       for(int m=1;m<n;m++)
       {
           if(near[m]!=0)
           {

               if(Cost[m][near[m]]<mm)
               {
                  mm=Cost[m][near[m]];
                  j=m;
               }
           }
       }
        t[i][1]=j;
        t[i][2]=near[j];
        minCost=minCost+Cost[j][near[j]];
        near[j]=0;

        for(int k=1;k<n;k++)
        {

            if((near[k]!=0) && (Cost[k][near[k]]>Cost[k][j]))
                near[k]=j;
        }

    }

    return minCost;
}



int main()
{
clock_t time;
    time = clock();

   cout<<"The minimum Cost Using prims algorithm is: "<<Prims()<<endl;

   time = ((clock() - time)*1000)/CLOCKS_PER_SEC;
    cout<<"\n\nExecution Time is = "<<time<<" ms "<<endl;

    return 0;
}



/*
Cost
{0,0,0,0,0,0,0},
{0,1000,1,2,1000,1000,1000},
{0,1,1000,3,1000,1000,1000},
{0,2,3,1000,4,5,6},
{0,1000,1000,4,1000,7,1000},
{0,1000,1000,5,7,1000,8},
{0,1000,1000,6,1000,8,1000}
};


Edge
{
{0,0,0,0},
{0,2,1,3},
{0,1,1,2},
{0,3,2,3},
{0,4,3,4},
{0,5,3,5},
{0,6,3,6},
{0,7,4,5},
{0,8,5,6}
};




Dense
Edges
{
{0,0,0,0},
{0,3,1,2},
{0,4,1,5},
{0,4,1,4},
{0,10,2,3},
{0,3,2,6},
{0,2,2,5},
{0,1,3,7},
{0,6,3,6},
{0,5,4,5},
{0,6,4,8},
{0,11,5,6},
{0,1,5,9},
{0,2,5,8},
{0,2,6,7},
{0,11,6,10},
{0,3,6,9},
{0,8,7,10},
{0,4,8,9},
{0,7,9,10},
};
cost
{
{0,0,0,0,0,0,0,0,0,0,0},
{0,1000,3,1000,4,4,1000,1000,1000,1000,1000},
{0,3,1000,10,1000,2,3,1000,1000,1000,1000},
{0,1000,10,1000,1000,1000,6,1,1000,1000,1000},
{0,4,1000,1000,1000,5,1000,1000,6,1000,1000},
{0,4,2,1000,5,1000,11,1000,2,1,1000},
{0,1000,3,6,1000,11,1000,2,1000,3,11},
{0,1000,1000,1,1000,1000,2,1000,1000,1000,8},
{0,1000,1000,1000,6,2,1000,1000,1000,4,1000},
{0,1000,1000,1000,1000,1,3,1000,4,1000,7},
{0,1000,1000,1000,1000,1000,11,8,1000,7,1000},
};



*/
