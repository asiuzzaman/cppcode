#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MX 100006

vector<pair<int,int> >v[MX];
bool vis[MX];
int dis[MX];
int node,edge;

void Dijkstra(){

   for(int i=1;i<=node;i++) dis[i]=MX;
   dis[1]=0;
   queue<int>Q;
   Q.push(1);
   while(!Q.empty()){
       int u=Q.front();
       Q.pop();
     //  cout<<"the U size :"<<v[u].size()<<endl;
       for(int i=0;i<v[u].size();i++){
           int child=v[u][i].first;
          // cout<<"Child: "<<child<<endl;
           if(dis[child]>dis[u]+v[u][i].second) {
               dis[child]=dis[u]+v[u][i].second;
               
               Q.push(child);
           }
       }
   }

   for(int i=2;i<=node;i++){
       cout<<dis[i]<<" ";
   }

}

int main() {

cin>>node;    
cin>>edge;

for(int i=0;i<edge;i++){
   int n1,w,n2;
   cin>>n1>>n2>>w;
   v[n1].push_back({n2,w});
}

Dijkstra();


}

/*

5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5


*/