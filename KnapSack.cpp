#include<bits/stdc++.h>
using namespace std;


int Knapsack(int W,int wt[],int val[],int n){

  
if(W==0 || n==0) return 0;
    if(wt[n-1]>W) 
         return Knapsack(W,wt,val,n-1);
    else 
        return max( val[n-1]+Knapsack(W-wt[n-1],wt,val,n-1) , Knapsack(W,wt,val,n-1));

}

int main(){
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int W=50;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<"Hello Knapsack"<<endl;
    int res=Knapsack(W,wt,val,n);    
    cout<<res<<endl;
}