#include <iostream>
//#include<limits.h>
using namespace std;
#define Node 50
#define INF 1234
int Graph[Node][Node];
int node,edge;
int dist[Node];
bool sptSet[Node];

int MinDist()
{
  int min = INF, minIndex;
  for (int i = 0; i < node; i++)
  {
    if (sptSet[i] == false and dist[i] <= min)
    {
      min = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}
void Initialization(){

  for (int i = 0; i < node; i++)
  {
    dist[i] = INF;
    sptSet[i] = false;
  }

}
void Dijkstra(int src)
{
  Initialization();
  dist[src] = 0;

  for (int i = 0; i < node; i++)
  {
    int u = MinDist();
    sptSet[u] = true;
    for (int v = 0; v < node; v++)
    {
      if (dist[v] > dist[u] + Graph[u][v] and Graph[u][v] and !sptSet[v] and dist[u] != INF)
      {
        dist[v] = dist[u] + Graph[u][v];
        
      }
    }
  }
  for(int i=0;i<node;i++){
    cout<<dist[i]<<" ";

  }
  cout<<endl;
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
  Dijkstra(src);
}