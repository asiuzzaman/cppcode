#include <bits/stdc++.h>
//#include<limits.h>
using namespace std;
#define Node 50
#define INF 1234
int Graph[Node][Node];
int node,edge;
int dist[Node];
bool sptSet[Node];
bool visited[Node];

void Initialization(){

  for (int i = 0; i < node; i++)
  {
    dist[i] = INF;
  }
}
int main()
{
     cin>>node;
    for(int i=0;i<node;i++){
      for(int j=0;j<node;j++){
       // Graph[i][j]=0;
        int x;
        cin>>x;
        Graph[i][j]=x;
      }
    }

  int src; 
   cin>>src;
    
  Initialization();
 
  dist[src]=0;
 
 queue<int>Q;
 visited[src]=1;
 Q.push(src);
 while(!Q.empty()){
   int u=Q.front();
   Q.pop();
   for(int v=0;v<node;v++){
      if(dist[v]>dist[u]+Graph[u][v] and !visited[v]){
        dist[v]=dist[u]+Graph[u][v]; 
        // cout<<"V: Dist v:"<<v<<" "<<dist[v]<<endl;
        visited[v]=1;
        Q.push(v);
      }
   } 
 }
 for(int i=0;i<node;i++){
   cout<<dist[i]<<" ";
 }


}

/*
2 
0 25
25 0
0

3
0 1 43 
1 0 6 
43 6 0
2

5
31 100 65 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20 
0 
*/