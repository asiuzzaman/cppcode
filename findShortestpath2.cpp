#include <iostream>
//#include<limits.h>
using namespace std;
#define Node 9

int MinDist(int dist[Node], bool sptSet[Node])
{
  int min = 123456789, minIndex;
  for (int i = 0; i < Node; i++)
  {
    if (sptSet[i] == false and dist[i] <= min)
    {
      // cout<<dist[i]<<endl;
      min = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void Dijkstra(int graph[Node][Node], int src)
{
  int dist[Node];
  bool sptSet[Node];

  for (int i = 0; i < Node; i++)
  {
    dist[i] = 123456789;
    sptSet[i] = false;
  }
  dist[src] = 0;

  for (int i = 0; i < Node; i++)
  {
    int u = MinDist(dist, sptSet);
    // cout<<u<<endl;
    sptSet[u] = true;
    for (int v = 0; v < Node; v++)
    {
      if (dist[v] > dist[u] + graph[u][v] and graph[u][v] and !sptSet[v] and dist[u] != 123456789)
      {
        dist[v] = dist[u] + graph[u][v];
        
      }
    }
  }
  for(int i=0;i<Node;i++){
    cout<<dist[i]<<" ";

  }
  cout<<endl;
}
int main()
{
    int Graph[Node][Node];
    for(int i=0;i<Node;i++){
      for(int j=0;j<Node;j++){
        Graph[i][j]=0;
      }
    }
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
      int x,y,w;
      cin>>x>>y>>w;
      Graph[x][y]=w;
      Graph[y][x]=w;
    }

  //  for(int i=0;i<Node;i++){
  //    for(int j=0;j<Node;j++){
  //      cout<<Graph[i][j]<<" ";

  //    }
  //    cout<<endl;
  //  } 
  int src = 0;
  Dijkstra(Graph, src);
}