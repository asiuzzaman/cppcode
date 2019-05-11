#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100];
queue<int>Q;
int x;
map<int,int>visited;

void BFS(int node){
     visited[node]=true;
     Q.push(node);
     visited[node]=1;
     while(!Q.empty()){
         int parent=Q.front();
         Q.pop();
         for(int i=0;i<graph[parent].size();i++){
            int child=graph[parent][i];
            if(visited[child]==0){
                Q.push(child);
                visited[child]=visited[parent]+1;
            }
         }
     }
}

int main(){
    int node;
    cin>>node;
    for(int i=0;i<node-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cin>>x;
   // cout<<x<<endl;
    BFS(1);

    int ans=0;
    for(int i=1;i<=node;i++){
        if(visited[i]==x) ans++;
    }
    cout<<ans<<endl;
}