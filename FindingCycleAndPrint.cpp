#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int Node,Edge;
vector<int>Adj[100];

int Grid[100][100];

bool visited[100];
bool recStack[100];
set<int>ans;


bool isCycleUtil(int u){
   //  cout<<"UUUU"<<u<<endl;
    if(!visited[u]){
    
        visited[u]=true;
        recStack[u]=true;
      
        for(int i=1;i<=Node;i++){
               // int v=Adj[u][i];
            if(!visited[i] and Grid[u][i] and isCycleUtil(i)) { ans.insert(i); return true;}
            else if(recStack[i] and Grid[u][i]){ans.insert(i);  return true;}
                
                
        }
    }
    recStack[u]=false;
    return false;
}

bool isCycle(){
    for(int i=0;i<=Node;i++){
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=1;i<=Node;i++){
        if(isCycleUtil(i)) return true;
    }
    return false;
}

int main() {
    cin>>Node>>Edge;
    for(int i=0;i<Edge;i++){
        int x,y;
        cin>>x>>y;
        //Adj[x].push_back(y);
        Grid[x][y]=1;
    }

    if(isCycle()){ cout<<"Cycle......."<<endl;}
    else cout<<"No cycle"<<endl;
      
     cout<<ans.size()<<endl;

     set<int>::iterator it=ans.begin();

     for(;it!=ans.end();it++){
         cout<<*it<<" ";
     }
     

}

/*
7 9
3 1
3 6
1 5
5 2
2 7
7 1
5 4
4 5
6 5

4 4 
1 2
2 3
3 4
1 4

 */