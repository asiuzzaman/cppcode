#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int>graph[1055];
int visited[1005]={0};
int ans=0;

void DFS(int n,int length){
   
    visited[n]=length;
    for(int i=0;i<graph[n].size();i++){
        int child=graph[n][i];
        if(visited[child]==0){
             DFS(child,length+1);
        }
    }

}

void Initialization(){
  for(int i=0;i<1005;i++){
      visited[i]=0;
      graph[i].clear();
  }
  
}   

int main(){
    int node;
    cin>>node;
    Initialization();
    for(int i=0;i<node-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int length=1;
    DFS(1,length);
   
    int q;
    cin>>q;
    int minIndx=INT_MAX;
    int minNum=0;

    while(q--){
        int num;
        cin>>num;
        if(minIndx>visited[num]){
            minIndx=visited[num];
            minNum=num;
        }
    }
    cout<<minNum<<endl;

}