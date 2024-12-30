#include <bits/stdc++.h>
using namespace std;
void LCS_algo(string x, string y, int m, int n){
    m = x.size(),n = y.size();
    int i, j,index;
    int L[m+1][n+1];


    for(int i=0; i<=m; i++){
        L[i][0]=0;
    }
    for(int i=0; i<=m; i++){
        L[0][i]=0;
    }

    for(int i=1 ;i<=m ;i++){
        for(int j =1; j<=n; j++){
            if(x[i-1] ==y[j-1]){
                L[i][j] = L[i-1][j-1]+1;

            }else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

index = L[m][n];
   char LCS[index + 1];
   LCS[index] = '\0';
   i = m, j = n;
   while (i > 0 && j > 0) {
      if (x[i - 1] == y[j - 1]) {
         LCS[index - 1] = x[i - 1];
         i--;
         j--;
         index--;
      } else if (L[i - 1][j] > L[i][j - 1])
         i--;
      else
         j--;
   }
   printf("LCS: %s\n", LCS);
}
int max(int a, int b){
return(a>b)?a:b;}
int main(){
    string y,x= "lullabybabies";
    y= "skullandbones";
   LCS_algo(x,y,x.size(), y.size());
}
