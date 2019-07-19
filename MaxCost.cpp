// MinCost recursion.......
/*
Given an NxM (N rows and M columns) integer matrix with non-negative values (0..MAX_INT inclusive).
 What is the maximum sum from going top left (0, 0) to bottom right (N-1, M-1) ? 
 The condition is that when you're at point (p, q), you can only move to either right (p, q+1) or down (p+1, q).

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 int Mat[10][10];

 int MINI(int x,int y,int z){
     return min(x,min(y,z));
 }
 
int MinCost(int r,int c){
   int tc[5][5];
   tc[0][0]=Mat[0][0];
   
   for(int i=1;i<r;i++){
       tc[i][0]=tc[i-1][0]+Mat[i][0];

   }

   for(int j=1;j<c;j++){
       tc[0][j]=tc[0][j-1]+Mat[0][j];
   }

   for(int i=1;i<r;i++){
       for(int j=1;j<c;j++){
           tc[i][j]=max(tc[i-1][j],tc[i][j-1])+Mat[i][j];
       }
   }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<tc[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

   return tc[r-1][c-1];
    
}


int main() {
    int R,C;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>Mat[i][j];
        }
    }
    int res=MinCost(R,C);
    cout<<res<<endl;
}
 
 /*
 
 3 3
 1 2 3
 4 8 2
 1 5 3


 */