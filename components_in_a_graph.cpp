#include<iostream>
using namespace std;
#define MX 2*1500
int Graph[MX][MX];
bool visited[MX];
int cnt;
int Node;
int  DFS(int u){
    visited[u]=1;
   // cout<<"U: "<<u<<endl;
    cnt++;
    for(int i=1;i<=2*Node;i++){
         if(!visited[i] and Graph[u][i]){
             DFS(i);
         }
        
    }
    return cnt; 
}
int main(){
    cin>>Node;
    for(int i=0;i<Node;i++){
        int x,y;
        cin>>x>>y;
        Graph[x][y]=1;
        Graph[y][x]=1;
    }

    int mx=-1,mn=MX;
    for(int i=1;i<=2*Node;i++) {  
        if(!visited[i] ){
            cnt=0;
            int ans=DFS(i);
            mx=max(mx,ans);
            if(ans>1){
                mn=min(mn,ans);
            }
        }
    }
   cout<<mn<<" "<<mx<<endl;
//    DFS(1);
//    for(int i=1;i<=2*Node;i++){
//        cout<<visited[i]<<" ";
//    }
   
   
    
}
/*
5
1 6 
2 7
3 8
4 9
2 6
*/