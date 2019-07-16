/*
    Frog Problem... Using  2D Matrix....
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int N,M;
int Grid[100][100];
bool visited[100][100];
int Level[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int x,int y){
    return (x>=1 and x<=N and y>=1 and y<=M and !visited[x][y] and Grid[x][y] );
}

void BFS(int srx,int sry){
    visited[srx][sry]=true;
    queue<pair<int,int> >Q;
    Q.push({srx,sry});
    
     Level[srx][sry]=0;
     
     while(!Q.empty()){
        pair<int,int>P;
        P=Q.front();
        Q.pop();
       
        int ux=P.first,uy=P.second;
       
        for(int i=0;i<4;i++){
             int vx=ux+dx[i];
            int vy=uy+dy[i];
           // cout<<vx<<" "<<vy<<endl;
            if(valid(vx,vy)){
                //cout<<vx<<" "<<vy<<" "<<ux<<" "<<uy<<endl;
                if(ux==vx) Level[vx][vy]=Level[ux][uy]+0;
                if(uy==vy) Level[vx][vy]=Level[ux][uy]+1;
                visited[vx][vy]=true;
               Q.push({vx,vy});
           }

       }
     }


}

int main() {
    
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>Grid[i][j];
        }
    }
    int srx,sry,desx,desy;
    cin>>srx>>sry>>desx>>desy;
    BFS(srx,sry);
    //cout<<srx<<" "<<sry<<endl;
   cout<<Level[desx][desy]<<endl;

//   for(int i=1;i<=N;i++){
//       for(int j=1;j<=M;j++){
//           cout<<Level[i][j]<<" ";
//       }
//       cout<<endl;
//   }
  

        
}

/*
4 5
1 1 1 1 1
1 1 0 1 0
1 1 1 1 0
1 1 1 1 1

1 1
2 4



10 10 

1 1 0 1 1 0 1 0 1 1
0 1 1 1 1 1 0 1 0 1
1 0 1 1 1 0 1 1 0 0
0 1 0 1 1 1 0 1 0 1
1 1 1 1 1 0 0 0 1 0
0 0 1 1 0 1 1 1 1 1
1 1 1 0 0 0 1 1 0 1
1 1 1 1 0 1 1 0 1 1
0 0 0 1 1 1 0 1 1 1
1 1 1 1 0 0 0 1 1 1

1 1 
10 10


*/