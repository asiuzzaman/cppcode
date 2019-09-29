#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 


 void PrintArray(int Arr[],int SZ){

    for(int i=0;i<SZ;i++){
       printf("%d ",Arr[i]);
    }
    printf("\n");
 }
void Merge(int Arr[],int l,int m,int r){
   //cout<<l<<" "<<m<<" "<<r<<endl;

   int i,j,k;
   int n1=m-l+1;
   int n2=r-m;
   
   // Create tempurary array...
   int L[n1],R[n2];

   for(i=0;i<n1;i++){
      L[i]=Arr[l+i];
   }
   for(j=0;j<n2;j++){
      R[j]=Arr[m+1+j];
   }
   i=0;
   j=0;
   k=l;
   while(i<n1 and j<n2){
      if(L[i]<=R[j]){
         Arr[k]=L[i];
         i++;
      }
      else {
         Arr[k]=R[j];
         j++;
      }
      k++;
   }
   while(i<n1){
      Arr[k]=L[i];
      i++;
      k++;
   }
   while(j<n2){
      Arr[k]=R[j];
      j++;
      k++;
   }

}

 void MergeSort(int Arr[],int l,int r){
      
      if(l<r){
         //cout<<l<<" "<<r<<endl;
         int m=l+(r-l)/2;
         MergeSort(Arr,l,m);
         MergeSort(Arr,m+1,r);
       //  cout<<"In Merge......."<<endl;
         Merge(Arr,l,m,r);
      }
 }

int main() {
   
   int Arr[]={12,11,13,5,6,7};
   int arr_size=sizeof(Arr)/sizeof(Arr[0]);
   

    printf("The Given Array.......\n");
    PrintArray(Arr,arr_size);
    MergeSort(Arr,0,arr_size-1);
    cout<<"After sorting........"<<endl;
    PrintArray(Arr,arr_size);
}