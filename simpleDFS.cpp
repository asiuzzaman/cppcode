#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100];
bool visited[100];
int node,edge;

void DFS(int u){
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(visited[v]==0){
            DFS(v);
        }
    }
}

int main(){
   cin>>node>>edge;
   for(int i=0;i<edge;i++){
       int x,y;cin>>x>>y;
       graph[x].push_back(y);
       graph[y].push_back(x);
   }
    int src,dist;
    cin>>src>>dist;
    DFS(src);
    if(visited[dist]==1) {
        cout<<dist<<" is rechable from src "<<src<<endl;
    }
    else cout<<dist<<" is not rechable from src "<<src<<endl;
}
       

 /*

 5 6
0 1
0 4
1 2 
2 3
3 4
1 4


  */      
