#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MX 100006

vector<pair<int,int> >v[MX];
bool vis[MX];
int dis[MX];


void Dijkstra(){

    memset(vis,false,sizeof(vis));
    dis[1]=0;
    multiset<pair<int,int> > S; 
    S.insert({0,1});  // Weight must be come first  because multiset return the min priority

    while(!S.empty()){
        pair<int,int>p=*S.begin();
        S.erase(S.begin());
        int x=p.second;
        int wei=p.first;
        
         if(vis[x]) continue;
         vis[x]=true;
       
        for(int i=0;i<v[x].size();i++){
            int e=v[x][i].first;
            int w=v[x][i].second;
            
            if(dis[x]+w<dis[e]){
                dis[e]=dis[x]+w;
              
                S.insert({dis[e],e});
            }
        }
    }
}

int main() {

int node;cin>>node;    
int edge;cin>>edge;

for(int i=0;i<edge;i++){
   int n1,w,n2;
   cin>>n1>>n2>>w;
   v[n1].push_back({n2,w});
}

for(int i=0;i<=node;i++) dis[i]=INT_MAX;
Dijkstra();
for(int i=2;i<=node;i++){
    cout<<dis[i]<<" ";
}
cout<<endl;

}

/*

7
1 2 1
1 4 2
1 3 7
2 3 3
3 5 1
3 4 5
4 5 7


*/