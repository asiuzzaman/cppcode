#include<bits/stdc++.h>
using namespace std;

vector<int>visited;
vector<int>graph[6];

void initialize(){
    for(int i=0;i<6;i++){
    visited.push_back(0);
  }

}

void bfs(int node){
  queue<int>Q;
  Q.push(node);
  visited[node]=true;
  int counter=0;
  while (!Q.empty())
  {    
       
       int fuck=Q.front();
       Q.pop();
       cout<<"node print kortesi:"<<fuck<<endl;
       for(int i=0;i<graph[fuck].size();i++){
           int temp=graph[fuck][i];
          
          if(!visited[temp]){
             Q.push(temp);
             visited[temp]=true;
           }
       }
       counter++;
  }
}

int main()
{
initialize();
int node=6,edge=8;

  for(int i=0;i<edge;i++){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  for(int i=1;i<=node;i++){
    if(!visited[i]){
      bfs(i);
    }
  }
  
}
 
/*

1 2
1 3
2 4
2 5
3 5
4 5
4 6
5 6

*/
 

