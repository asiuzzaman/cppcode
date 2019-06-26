/*
   A problem which has n elements in an array. Imagine the Elements are the pages of a memory.
   For Each pages there are some elments called per pages elements.
   Given a Page Index and its order.
   For Order 0 for increasing order print the elements
   1 for decreasing order.
   
*/
#include<bits/stdc++.h>
using namespace std;
int ara[100];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    vector<int>v;
    int pageIndex;
    cin>>pageIndex;
    int perPage;
    cin>>perPage;
    for(int i=(pageIndex-1)*perPage+1;i<=pageIndex*perPage and i<=n;i++){
       v.push_back(ara[i]);
    }
    int order;
    cin>>order;
    if(order==0){
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    }
    else{

        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    }

}
/*
20
4 5 6 2 1 7 8 9 10 23 0 6 1 77 88 99 2 90 19 20
1 8 1 

*/