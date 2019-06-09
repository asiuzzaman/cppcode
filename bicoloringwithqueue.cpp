#include<bits/stdc++.h>
using namespace std;
#define V 20005
int G[V][V];
bool isBipartite(int Graph[][V],int src){
  
  int colorVertex[V];
  for(int i=0;i<V;i++){
    colorVertex[i]=-1;
  }
  queue<int>Q;
  Q.push(src);
  colorVertex[src]=1;
  while(!Q.empty()){
    int u=Q.front();
    Q.pop();
    if(Graph[u][u]==1) return false;
    for(int v=0;v<V;v++){
      if(Graph[u][v] and colorVertex[v]==-1){
        colorVertex[v]=1-colorVertex[u];
        Q.push(v);
      }
      else if(Graph[u][v] and colorVertex[v]==colorVertex[u]) return false;
    }
  }
  return true;
}
int main(){
  int node,edge;
  
  while(cin>>node and node!=0){
      cin>>edge;
      for(int i=0;i<20005;i++){
        for(int j=0;j<20005;j++){
          G[i][j]=0;
        }
      }
       for(int i=0;i<edge;i++){
        int x,y;cin>>x>>y;
        G[x][y]=1;
        G[y][x]=1;
      }

    isBipartite(G,0)?cout<<"BICOLORABLE."<<endl:cout<<"NOT BICOLORABLE."<<endl; 
  }
}