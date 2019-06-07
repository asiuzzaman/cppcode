#include <bits/stdc++.h>
using namespace std;
#define INF 12345678
#define SZ 10


vector<pair<int, int>> adj[SZ];
int edge, node;

int main()
{
  cin >> node >> edge;
  vector<int> dist(node, INF);

  for (int i = 0; i < edge; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
 
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0}); // 1st element 0 is the weight of 0 vertics
  dist[0] = 0;

  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    for (int i = 0; i < adj[u].size(); i++)
    {

      int v = adj[u][i].first;
      int weight = adj[u][i].second;
      if (dist[v] > dist[u] + weight)
      {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }  
   cout<<"The Result:"<<endl;
  for (int i = 0; i < node; i++)
  {
    cout << i << " " << dist[i] << endl;
  }
  
}

/*
 9 14 
 0 1 4
 0 7 8
 1 2 8
 1 7 11
 2 3 7
 2 8 2
 2 5 4
 3 4 9
 3 5 14
 4 5 10
 5 6 2
 6 7 1
 6 8 6
 7 8 7

 */