//Problem Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/1
#include<iostream>
using namespace std;
#define SZ 55

int N,M;
int Graph[SZ][SZ];
bool visited[SZ][SZ];
int cnt;
int dx[]={1,-1,0,0,1,-1,-1,1};
int dy[]={0,0,1,-1,1,1,-1,-1};

bool valid(int x,int y){
   return (x>=0 and x<N and y>=0 and y<M and Graph[x][y] and !visited[x][y]);
}
void DFS(int x,int y){
   cnt++;
   visited[x][y]=1;
   for(int i=0;i<8;i++){
      int vx=x+dx[i];
      int vy=y+dy[i];
      if(valid(vx,vy)){
        // cout<<"vx :"<<vx<<"vy: "<<vy<<endl;
        DFS(vx,vy);
      }
   }
   return;
}
int main(){

   int test;
   cin>>test;
   while(test--){
   cin>>N>>M;
   for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
         cin>>Graph[i][j];
         visited[i][j]=0;
      }
   }
   int mx=0;
   for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
         cnt=0;
         if(Graph[i][j]){
            DFS(i,j);
            mx=max(mx,cnt);
         }
      }
      
   }
  cout<<mx<<endl;
   }
}
/*
 3 3
1 1 0
0 0 1
1 0 1

1 3
1 1 1

 */